//
// Created by alican on 10.05.2016.
//

#include <iostream>
#include "Chromosome.h"
#include "GeneticAlgorithm.h"

std::random_device randomDevice2;
std::default_random_engine randomEngine(randomDevice2());
std::uniform_int_distribution<int> uniform_dist(0, 2);


Chromosome::Chromosome() { }



void Chromosome::calcFitness() {
    std::cout << "Fitness: " << pairs.size() << std::endl;
    std::cout << "Collisions: " << collisions << std::endl;
    for (auto pair : pairs){
        std::cout << "Paar " << pair.first.representation() << " und " << pair.second.representation() << std::endl;
    }
}


void Chromosome::createRandomTurnList() {

        for (auto character : GeneticAlgorithm::params.sequence ){
            int turn = uniform_dist(randomEngine) - 1;
            turnList.push_back((TURNCODE)turn);
        }
    std::cout << "Fertig" << std::endl;

}

void Chromosome::createCoordinatePath(Coordinate start) {
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
    std::cout << "\n";
}

void Chromosome::printTurns() {

    for (auto turn : turnList){

        std::cout << turn;
    }
    std::cout << "\n";
}

bool Chromosome::isPair(Coordinate &first, Coordinate &second) {
    return abs((second.x - first.x)) + abs((second.y - first.y)) == 1;
}

void Chromosome::walkPath() {
    Coordinate cord1;
    Coordinate cord2;
    for (int i = 0; i < path.size(); i++){
        cord1 =  path.at(i);
        for(int j = i + 2; j < path.size(); j++){
            cord2 = path.at(j);
            if(cord1.x == cord2.x && cord1.y == cord2.y) {
                collisions++;
            }
            if(GeneticAlgorithm::params.sequence.at(i) == '1' && GeneticAlgorithm::params.sequence.at(j)){
                if (isPair(path.at(i), path.at(j))){
                    pairs.push_back(std::make_pair<Coordinate, Coordinate>(
                            (Coordinate &&) path.at(i),
                            (Coordinate &&) path.at(j))
                    );
                }
            }
        }
    }
}

void Chromosome::process() {
    path.clear();
    pairs.clear();
    collisions = 0;
    Coordinate start;
    createCoordinatePath(start);
    walkPath();
    calcFitness();
}

void Chromosome::crossover(Chromosome &other) {

    std::uniform_int_distribution<int> mutation(0, turnList.size());
    int position =  5; // mutation(randomEngine);

    auto list1 = this->turnList;
    auto list2 = other.turnList;

    auto it1 = list1.begin();
    std::advance(it1, position);
    auto it2 = list2.begin();
    std::advance(it2, position);

    list1.splice(it1, list2, it2, list2.end());
    list2.splice(list2.end(), list1, it1, list1.end());
}




















