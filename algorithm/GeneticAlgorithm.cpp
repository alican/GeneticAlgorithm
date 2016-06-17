//
// Created by alican on 09.05.2016.
//

#include <iostream>
#include "GeneticAlgorithm.h"

void GeneticAlgorithm::run() {

    Population p = createBasePopulation();
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


        generations.front().printBestCandidate();

        std::cout << "Min Fitness: " << p.minFitness << std::endl;
        std::cout << "Max Fitness: " << p.maxFitness << std::endl;

        generations.push_back(p);
     }

    toJson();
}

Population GeneticAlgorithm::createBasePopulation() {
    Population base(params.populationSize);
    return base;
}

bool GeneticAlgorithm::keepGoing() {
    return false;
}

void GeneticAlgorithm::toJson() {
    //json j_vec(generations);
    //std::cout << j_vec << std::endl;
}









