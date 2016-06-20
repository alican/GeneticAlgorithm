//
// Created by alican on 10.05.2016.
//
#ifndef GENETICALGORITHM_POPULATION_H
#define GENETICALGORITHM_POPULATION_H

#include "Chromosome.h"
#include <vector>
#include <iostream>
#include "../lib/json.hpp"

using json = nlohmann::json;

class Population {
public:

    Population() { }

    Population(unsigned long size) {

        for (int i = 0; i < size; i++){
            Chromosome chrom;
            chrom.createRandomTurnList();
            chrom.process();
            chrom.setId();
            chromosomes.push_back(std::move(chrom));
        }
    }

    Population(std::vector<Chromosome> selection){
        chromosomes = selection;
    }

    Population selection();
    void mutation(double);
    void crossover_selection(double crossover_rate);
    void process();
    void printChromos();
    void printBestCandidate();

    double minFitness;
    double maxFitness;
    double averageFitness;


    json toJson();


private:
    std::vector<Chromosome> chromosomes;
};

#endif //GENETICALGORITHM_POPULATION_H
