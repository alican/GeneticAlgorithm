//
// Created by alican on 10.05.2016.
//

#include <iostream>
#include <functional>
#include "Population.h"

Population Population::selection() {
    return Population(chromosomes);
}

void Population::crossover(double crossover_rate) {

    // 0.25 der chromosome.
    //Fisher-Yates shuffle
    int crossover_count = (int) (chromosomes.size() * crossover_rate );

    std::cout << "crossover_count " << crossover_count << std::endl;
    int num_random = crossover_count;
    long left = std::distance(chromosomes.begin(), chromosomes.end());
    auto current = chromosomes.begin();

    while (num_random--) {
        auto r = current;
        std::advance(r, rand()%left);
        std::swap(*current, *r);

        ++current;
        --left;
    }


    for(auto it = chromosomes.begin(); it < current; it +=2) {
        Chromosome& ch1 = *(it);
        Chromosome& ch2 = *(it +1);
        ch1.crossover(ch2);
        ch1.process();
        ch2.process();
    }
}

void Population::mutation() {



}

void Population::printChromos() {

    for (auto chromo : chromosomes){
        chromo.printCoordinates();
    }
    std::cout << chromosomes.size()<< std::endl;
}







