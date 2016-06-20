//
// Created by alican on 09.05.2016.
//

#include <iostream>
#include <fstream>
#include "GeneticAlgorithm.h"

void GeneticAlgorithm::run() {


    Population p = createBasePopulation();
    p.process();
    generations.push_back(p);

    double fitness = 0.001;
    int generation = 0;

    while(generation < params.generations){
        //p.printChromos();
        generation++;
        p = p.selection();
        p.crossover_selection(params.crossoverPercent);
        p.mutation(params.mutationPercent);
        p.process();


        p.printBestCandidate();

       // std::cout << "Min Fitness: " << p.minFitness << std::endl;
       // std::cout << "Max Fitness: " << p.maxFitness << std::endl;

        generations.push_back(p);
     }

    //resultToFile();
    resultAsJson();
}

Population GeneticAlgorithm::createBasePopulation() {
    Population base(params.populationSize);
    return base;
}

bool GeneticAlgorithm::keepGoing() {
    return false;
}

void GeneticAlgorithm::resultAsJson() {
    json results;
    json min;
    json max;
    json average;

    int generation = 0;
    for (auto p : generations){
        min.push_back(json::object({{"x", generation},{"y", p.minFitness}}));
        max.push_back(json::object({{"x", generation},{"y", p.maxFitness}}));
        average.push_back(json::object({{"x", generation},{"y", p.averageFitness}}));
        generation++;
        //results.push_back(p.toJson());
    }
    results["min"] =  min;
    results["max"] =  max;
    results["average"] =  average;

    std::ofstream myfile ("C:\\Users\\alican\\ClionProjects\\GeneticAlgorithm\\viewer\\results.json");
    if (myfile.is_open())
    {
        myfile << "data = " << results;
        myfile.close();
    }

}

void GeneticAlgorithm::resultToFile() {
    std::ofstream myfile ("C:\\Users\\alican\\ClionProjects\\GeneticAlgorithm\\viewer\\results.tsv");
    if (myfile.is_open())
    {
        myfile << "Generation" << "\t" << "max fitness" << "\t" << "min fitness" << "\t" << "average fitness" << "\n";
        for (auto p : generations){
            myfile << p.minFitness << "\t" << p.maxFitness << "\t" << p.averageFitness << "\n";
        };
        myfile.close();
    }
}












