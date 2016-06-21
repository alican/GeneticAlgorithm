//
// Created by alican on 10.05.2016.
//

#include <iostream>
#include "Chromosome.h"
#include "GeneticAlgorithm.h"



std::random_device randomDevice2;
std::default_random_engine randomEngine(randomDevice2());
std::uniform_int_distribution<int> uniform_dist(0, 2);


Chromosome::Chromosome() {
    id = idGlobal++;
}



void Chromosome::calcFitness() {

   // std::cout << "pairs" << pairs.size() << std::endl;
   // std::cout << "collisions" << collisions << std::endl;

    fitness = 1;
    fitness += pairs.size() * 100;
    if ((collisions) > 0){
        if (collisions == 1){
            collisions++;
        }
        fitness /= (collisions*collisions);
    }

   // std::cout << "fitness" << fitness << std::endl;


}


void Chromosome::createRandomTurnList() {
        for (int i = 0; i  < GeneticAlgorithm::params.sequence.length() - 1; i++ ){
            int turn = uniform_dist(randomEngine) - 1;
            turnList.push_back((TURNCODE)turn);
        }
}

void Chromosome::createCoordinatePath(Coordinate start) {
    pathList.clear();
    Coordinate current = start;
    pathList.push_back(current);
    for (auto turn: turnList){
        Coordinate next = current;
        next.turnTo(turn);
        pathList.push_back(next);
        current = next;
    }
}



void Chromosome::printCoordinates() {

    for (auto coordinate : pathList){

        std::cout << coordinate.representation();
    }
    std::cout << "\n";
}

void Chromosome::printTurns() {

    for (auto turn : turnList){

        std::cout << turn << " ";
    }
    std::cout << "\n";
}

bool Chromosome::isPair(Coordinate &first, Coordinate &second) {
    return abs((second.x - first.x)) + abs((second.y - first.y)) == 1;
}

void Chromosome::walkPath() {

    // reset collisions counter;
    this->collisions = 0;
    pairs.clear();


    Coordinate cord1;
    Coordinate cord2;

    for (size_t i = 0; i < pathList.size(); i++){
        cord1 =  pathList.at(i);
        for(size_t j = i + 2; j < pathList.size(); j++){
            cord2 = pathList.at(j);
            if(cord1.x == cord2.x && cord1.y == cord2.y) {
                collisions++;
            }
            if(GeneticAlgorithm::params.sequence.at(i) == '1' && GeneticAlgorithm::params.sequence.at(j)){
                if (isPair(pathList.at(i), pathList.at(j))){
                    pairs.push_back(std::make_pair<Coordinate, Coordinate>(
                            (Coordinate &&) pathList.at(i),
                            (Coordinate &&) pathList.at(j))
                    );
                }
            }
        }
    }
}

void Chromosome::process() {

    if (changed){
        Coordinate start;
        createCoordinatePath(start);
        walkPath();
        calcFitness();
        changed = false;
    }

}

void Chromosome::crossover(Chromosome& other) {

    std::uniform_int_distribution<int> crossover(1, turnList.size()-1);
    int position =  crossover(randomDevice2);

    std::vector<TURNCODE>& list1 = this->turnList;
    std::vector<TURNCODE>& list2 = other.turnList;

    auto it1 = list1.begin();
    std::advance(it1, position);
    auto it2 = list2.begin();
    std::advance(it2, position);

    std::vector<TURNCODE> nlist1;
    std::vector<TURNCODE> nlist2;
    nlist1.insert(nlist1.begin(), list1.begin(), it1);
    nlist1.insert(nlist1.end(), it2, list2.end());
    nlist2.insert(nlist2.begin(), list2.begin(), it2);
    nlist2.insert(nlist2.end(), it1, list1.end());

    list1 = std::move(nlist1);
    list2 = std::move(nlist2);


    // Mark as changed for recalculation of fitness, collusion, path etc.
    this->changed = true;
    this->setId();
    other.changed = true;
    other.setId();
}



int Chromosome::idGlobal = 0;

void Chromosome::mutate() {
    std::uniform_int_distribution<int> randomAccess(0, (int) turnList.size()-1);
    std::uniform_int_distribution<int> randomTurnCode(0, 2);
    int position = randomAccess(randomDevice2) ;
    int mutation = randomTurnCode(randomDevice2) -1 ;
    turnList.at(position) = (TURNCODE) mutation;

    // Mark as changed for recalculation of fitness, collusion, path etc.
    this->changed = true;
    this->setId();
}

void Chromosome::printInfo() {
    std::cout << "### Bester Kandidat ###" << std::endl;
    std::cout << "Pairs: " << pairs.size() << std::endl;
    std::cout << "Collisions: " << collisions << std::endl;
    std::cout << "Fitness: " << fitness << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "#######################" << std::endl;

    json j_vec(turnList);
    std::cout << j_vec << std::endl;
    printCoordinates();

}

void Chromosome::setId() {
    this->id = ++idGlobal;
}




