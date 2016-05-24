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
    HP polarisation;

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


private:
    std::vector<std::pair<Coordinate, Coordinate>> pairs;

    void crossover(int pos, Chromosome chromosome);

    void walkPath();
    void calcFitness();
    double fitness;

    int collisions = 0;
    std::list<TURNCODE> turnList;
    std::vector<Coordinate> path;
    void createCoordinatePath(Coordinate start);
    bool isPair(Coordinate &first, Coordinate &secound);

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
