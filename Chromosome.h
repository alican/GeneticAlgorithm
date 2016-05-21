//
// Created by alican on 10.05.2016.
//

#ifndef GENETICALGORITHM_GENOTYPE_H
#define GENETICALGORITHM_GENOTYPE_H


#include <string>
#include <list>

enum TURNCODE { LEFT, RIGHT, FORWARD };


class Chromosome {

public:


    Chromosome();

private:



    void crossover(Chromosome chromosome);
    void crossover(int pos, Chromosome chromosome);

    void calcFitness();
    double fitness;

    std::list<TURNCODE> turnList;
    std::list<std::pair<int, int>> coordinates;
};




/*
 *
 * 0,0      0,1     0,2     0,3,    0,4
 * 1,0      1,1     1,2     1,3,    1,4
 * 2,0      2,1     2,2     2,3,    2,4
 * 3,0      3,1     3,2     3,3,    3,4
 *
 */

#endif //GENETICALGORITHM_GENOTYPE_H
