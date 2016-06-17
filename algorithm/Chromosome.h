//
// Created by alican on 10.05.2016.
//

#ifndef GENETICALGORITHM_GENOTYPE_H
#define GENETICALGORITHM_GENOTYPE_H


#include <string>
#include <vector>
#include <list>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>

enum TURNCODE { LEFT = -1, FORWARD = 0, RIGHT = 1 };
enum FACING { NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3 };
enum HP { HYDROPHIL, HYDROPHOB };



//Fisher–Yates shuffle
template<class fwditer>
fwditer random_unique(fwditer begin, fwditer end, size_t num_random) {
    long left = std::distance(begin, end);
    while (num_random--) {
        fwditer r = begin;
        std::advance(r, rand()%left);
        std::swap(*begin, *r);
        ++begin;
        --left;
    }
    return begin;
}

struct Coordinate {
    int x = 0;
    int y = 0;   // (0,0)
    FACING facing = NORTH;
    //HP polarisation;

    std::string representation(){
        return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
    }
    void turnTo(TURNCODE turn){
        /*        N = 0
         *    W = 3    E = 1
         *        S = 2
         */
        int newFacing = facing + turn;
        if (newFacing == 4){
            newFacing = 0;
        }
        if (newFacing == -1){
            newFacing = 3;
        }
        facing = (FACING) newFacing;

        switch (facing){
            case NORTH:
                y += 1;
                break;
            case EAST:
                x += 1;
                break;
            case SOUTH:
                y -= 1;
                break;
            case WEST:
                x -= 1;
                break;
        }
    }
};


class Chromosome {

public:

    Chromosome();
    void printCoordinates();
    void process();
    void createRandomTurnList();
    void crossover(Chromosome& other);
    void printTurns();
    void mutate();
    void printInfo();

    static int idGlobal;
    int id = 0;

    bool operator< (const Chromosome& right) const {
        return fitness < right.fitness;
    }

    double getFitness() const {
        return fitness;
    }

    std::vector<TURNCODE> turnList;





private:
    std::vector<std::pair<Coordinate, Coordinate>> pairs;

    //void crossover(int pos, Chromosome chromosome);

    void walkPath();
    void createCoordinatePath(Coordinate start);
    void calcFitness();
    double fitness;
    int collisions = 0;

    bool changed = true;
    std::vector<Coordinate> pathList;
    bool isPair(Coordinate &first, Coordinate &secound);

};

#endif //GENETICALGORITHM_GENOTYPE_H
