//
// Created by alican on 10.05.2016.
//
#ifndef GENETICALGORITHM_POPULATION_H
#define GENETICALGORITHM_POPULATION_H

#include "Chromosome.h"
#include <vector>

class Population {

public:
    double averageFitness;

private:
    std::vector<Chromosome> genoTypeList;



};


#endif //GENETICALGORITHM_POPULATION_H
