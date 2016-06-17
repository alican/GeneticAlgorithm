//
// Created by alican on 10.05.2016.
//

#include <iostream>
#include <functional>
#include "Population.h"

Population Population::selection() {

    std::default_random_engine generator;
    std::exponential_distribution<double> distribution(2.5);

    std::vector<Chromosome> new_chromosomes;

    for(int i = 0; i < chromosomes.size();){
        double number = distribution(generator);

        if (number<1.0){
            i++;
            int position = int(chromosomes.size()*number);
            new_chromosomes.push_back(chromosomes.at(position));
        }
    }

    return Population(new_chromosomes);
}

void Population::crossover_selection(double crossover_rate) {

    // 0.25 der chromosome.
    //Fisher-Yates shuffle
    int crossover_count = (int) (chromosomes.size() * crossover_rate );
    crossover_count = 4;

    int num_random = 2;
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
        Chromosome& ch1 = (*(it));
        Chromosome& ch2 = *(it +1);
        ch1.crossover(ch2);
    }

}

void Population::mutation(double mutation_rate) {
    /*
     *   Wahl der Mutationen innerhalb der Population
     *
     */
    //double mutation_count = std::ceil((chromosomes.size() * mutation_rate ));
    double mutation_count = chromosomes.size();

    long size = chromosomes.size();
    auto current = chromosomes.begin();

    while (mutation_count--) {
        auto r = current;
        std::advance(r, rand()%size);
        (*(r)).mutate();
    }


}

void Population::printChromos() {


    for (auto chromo : chromosomes){
        std::cout << chromo.id << ": ";
        chromo.printTurns();
    }
    std::cout << chromosomes.size()<< std::endl;
}

void Population::process() {

    // re-calculate changed chromosomes
    for (auto chromo : chromosomes){
        chromo.process();
    }
    // sort list by fitness
    std::sort(chromosomes.rbegin(), chromosomes.rend());
    // calculate min/max fitness of population

    minFitness = chromosomes.back().getFitness();
    maxFitness = chromosomes.front().getFitness();
    // calculate average fitness of population
}

void Population::printBestCandidate() {
    chromosomes.front().printInfo();
}



