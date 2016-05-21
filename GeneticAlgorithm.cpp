//
// Created by alican on 09.05.2016.
//

#include <iostream>
#include "GeneticAlgorithm.h"

void GeneticAlgorithm::run() {

    createBasePopulation();


}

void GeneticAlgorithm::createBasePopulation() {

    population.resize(populationSize);

    for (auto chromo : population){
        std::cout << "A";
    }

}



