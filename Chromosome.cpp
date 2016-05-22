//
// Created by alican on 10.05.2016.
//

#include <iostream>
#include <random>
#include "Chromosome.h"
#include "GeneticAlgorithm.h"

std::random_device randomDevice2;
std::default_random_engine randomEngine(randomDevice2());
std::uniform_int_distribution<int> uniform_dist(0, 2);


Chromosome::Chromosome() {

    createRandomTurnList();
    Coordinate start;
    createCoordinatePath(start);
}

void Chromosome::calcFitness() {

    for (auto coordinate : path){

    }

}

void Chromosome::createRandomTurnList() {

        for (auto character : GeneticAlgorithm::params.sequence ){
            int turn = uniform_dist(randomEngine) - 1;
            turnList.push_back((TURNCODE)turn);
            std::cout << turn << std::endl;
        }
    std::cout << "Fertig" << std::endl;

}

void Chromosome::createCoordinatePath(Coordinate start) {
    path.push_back(start);
    Coordinate current = start;

    for (auto turn: turnList){
        Coordinate next = current;
        next.turnTo(turn);
        path.push_back(next);
        current = next;
    }
}



void Chromosome::printCoordinates() {
    for (auto coordinate : path){
        std::cout << coordinate.representation();
    }
    std::cout << "Next" << std::endl;
}










