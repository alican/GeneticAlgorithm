//
// Created by alican on 09.05.2016.
//

#include <iostream>
#include "GeneticAlgorithm.h"

void GeneticAlgorithm::run() {

    createBasePopulation();

    for (auto pop : population){
        pop.printCoordinates();
    }



}

void GeneticAlgorithm::createBasePopulation() {


    population.resize(params.populationSize);

    for (auto chrom : population){
        std::cout << "A";
    }
}





