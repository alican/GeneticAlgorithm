//
// Created by alican on 10.05.2016.
//
#ifndef GENETICALGORITHM_POPULATION_H
#define GENETICALGORITHM_POPULATION_H

#include "Chromosome.h"
#include <vector>
#include <iostream>

class Population {


public:


    Population() { }

    Population(unsigned long size) {

        for (int i = 0; i < size; i++){
            Chromosome chrom;
            chrom.createRandomTurnList();
            chrom.process();
            chromosomes.push_back(chrom);
        }
    }

    Population(std::vector<Chromosome> selection){
        chromosomes = selection;
    }

    Population selection();
    void crossover(double crossover_rate);

    void mutation();

    void printChromos();

public:
    double averageFitness;

private:
    std::vector<Chromosome> chromosomes;


};


#endif //GENETICALGORITHM_POPULATION_H
