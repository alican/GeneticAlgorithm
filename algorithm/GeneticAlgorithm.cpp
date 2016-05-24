//
// Created by alican on 09.05.2016.
//

#include <iostream>
#include "GeneticAlgorithm.h"

void GeneticAlgorithm::run() {

    Population p = createBasePopulation();
    population.push_back(p);

    double fitness = 0.001;
    int generation = 0;

    while(generation < params.generations){
        // p.printChromos();
        generation++;
        p = p.selection();
        p.crossover(params.crossoverPercent);
        p.mutation();
        population.push_back(p);

    }

    for (auto p : population){
    }

    std::cout << population.size();
}

Population GeneticAlgorithm::createBasePopulation() {
    Population base(params.populationSize);
    return base;
}

bool GeneticAlgorithm::keepGoing() {
    return false;
}






