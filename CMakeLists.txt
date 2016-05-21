cmake_minimum_required(VERSION 3.5)
project(GeneticAlgorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp GeneticAlgorithm.cpp GeneticAlgorithm.h Population.cpp Population.h Chromosome.cpp Chromosome.h)
add_executable(GeneticAlgorithm ${SOURCE_FILES})