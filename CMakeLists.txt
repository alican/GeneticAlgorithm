cmake_minimum_required(VERSION 3.5)
project(GeneticAlgorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp algorithm/GeneticAlgorithm.cpp algorithm/GeneticAlgorithm.h algorithm/Population.cpp algorithm/Population.h algorithm/Chromosome.cpp algorithm/Chromosome.h)
add_executable(GeneticAlgorithm ${SOURCE_FILES})