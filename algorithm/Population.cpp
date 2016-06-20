//
// Created by alican on 10.05.2016.
//

#include <iostream>
#include <functional>
#include "Population.h"

Population Population::selection() {

    std::default_random_engine generator;
    std::exponential_distribution<double> distribution(0.5);

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
    std::cout << crossover_count << std::endl;

    long left = std::distance(chromosomes.begin(), chromosomes.end());
    auto current = chromosomes.begin();

    while (crossover_count) {
        auto r = current;
        std::advance(r, rand()%left);
        //std::swap(*current, *r);
        Chromosome& ch1 = (*(current));
        Chromosome& ch2 = (*(r));

        if(ch1.id != ch2.id){
            ch1.crossover(ch2);
            --crossover_count;
        }
        ++current;
        --left;
    }

  /*  for(auto it = chromosomes.begin(); it < current; it +=2) {
        Chromosome& ch1 = (*(it));
        Chromosome& ch2 = *(it +1);
        ch1.crossover(ch2);
    }*/

}

void Population::mutation(double mutation_rate) {
    /*
     *   Wahl der Mutationen innerhalb der Population
     *
     */
    double mutation_count = std::ceil((chromosomes.size() * mutation_rate ));
    //double mutation_count = chromosomes.size();

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

    double totalFitness = 0;
    // re-calculate changed chromosomes
    for (Chromosome& chromo : chromosomes){
        chromo.process();
        totalFitness += chromo.getFitness();
    }
    // sort list by fitness
    std::sort(chromosomes.rbegin(), chromosomes.rend());
    // calculate min/max fitness of population

    minFitness = chromosomes.back().getFitness();
    maxFitness = chromosomes.front().getFitness();
    averageFitness = totalFitness/chromosomes.size();
}

void Population::printBestCandidate() {
    std::sort(chromosomes.rbegin(), chromosomes.rend());
    chromosomes.front().printInfo();
}

json Population::toJson() {
    json j;
    j["minFitness"] = minFitness;
    j["maxFitness"] = maxFitness;
    j["averageFitness"] = averageFitness;
    return j;
}
