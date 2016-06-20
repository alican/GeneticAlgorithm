#include <iostream>
#include <list>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <vector>


#include "algorithm/GeneticAlgorithm.h"

using namespace std;

// benchmark sequences for the 2d HP model
// 0 = hydrophil, "white"
// 1 = hydrophob, "black"
// data source: Ron Unger, John Moult: Genetic Algorithms for Protein Folding Simulations,
//         Journal of Molecular Biology, Vol. 231, No. 1, May 1993

std::string SEQ20 = "10100110100101100101";
std::string SEQ24 = "110010010010010010010011";
std::string SEQ25 = "0010011000011000011000011";
std::string SEQ36 = "000110011000001111111001100001100100";
std::string SEQ48 = "001001100110000011111111110000001100110010011111";
std::string SEQ50 = "11010101011110100010001000010001000101111010101011";


GeneticAlgorithmParams GeneticAlgorithm::params = {
        SEQ50,  // sequence
        100,     // populationSize
        300,     // generations
        0.10,   // elitePercent
        0.25,   // crossoverPercent
        0.15    // mutationPercent
};

std::ostream& operator<<(std::ostream& ostr, const std::vector<std::string>& list) {
    for (auto &i : list) {
        ostr << " " << i;
    }
    return ostr;
}


int main() {
    GeneticAlgorithm geneticAlgorithm;
    geneticAlgorithm.run();

/*
    int position = 4;


    std::vector<std::string> list1 = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",};
    std::vector<std::string> list2 = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J",};

    auto it1 = list1.begin();
    std::advance(it1, position);
    auto it2 = list2.begin();
    std::advance(it2, position);


    std::vector<std::string> nlist1;
    std::vector<std::string> nlist2;
    nlist1.insert(nlist1.begin(), list1.begin(), it1);
    nlist1.insert(nlist1.end(), it2, list2.end());
    nlist2.insert(nlist2.begin(), list2.begin(), it2);
    nlist2.insert(nlist2.end(), it1, list1.end());


    std::cout << "list1: " << list1 << "\n";
    std::cout << "list2: " << list2 << "\n";
    std::cout << "nlist1: " << nlist1 << "\n";
    std::cout << "nlist2: " << nlist2 << "\n";*/

    return 0;
}

