//
// Created by alican on 10.05.2016.
//

#ifndef GENETICALGORITHM_GENOTYPE_H
#define GENETICALGORITHM_GENOTYPE_H


#include <string>
#include <list>

enum TURNCODE { LEFT = -1, FORWARD = 0, RIGHT = 1 };
enum FACING { NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3 };
enum HP { HYDROPHIL, HYDROPHOB };


struct Coordinate {
    int x, y;   // (0,0)
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


private:

    void createRandomTurnList();

    void crossover(Chromosome chromosome);
    void crossover(int pos, Chromosome chromosome);

    void calcFitness();
    double fitness;

    std::list<TURNCODE> turnList;
    std::list<Coordinate> path;

    void createCoordinatePath(Coordinate start);

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
