#ifndef GENETICALGORITHM_GENETICALGORITHM_H
#define GENETICALGORITHM_GENETICALGORITHM_H

#include <string>
#include <vector>
#include "Chromosome.h"


class GeneticAlgorithm {


public:




    GeneticAlgorithm(
            const std::string &sequence,
            unsigned long populationSize,
            unsigned long generations,
            double elitePercent,
            double crossoverPercent,
            double mutationPercent) :
            sequence(sequence),
            populationSize(populationSize),
            generations(generations),
            elitePercent(elitePercent),
            crossoverPercent(crossoverPercent),
            mutationPercent(mutationPercent) { }

    void run();

private:
    std::string sequence;
    unsigned long populationSize;
    unsigned long generations = 200;
    double elitePercent = .10;
    double crossoverPercent = .80;
    double mutationPercent;

    void createBasePopulation();


    std::vector<Chromosome> population;
};


#endif //GENETICALGORITHM_GENETICALGORITHM_H
