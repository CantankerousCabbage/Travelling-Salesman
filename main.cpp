#include "Algorithm.h"
#include "BruteForce.h"
#include "FastOne.h"
#include "FastTwo.h"
#include "AGraphGen.h"

#include <iostream>
#include <memory>
#include <map>

using std::string;
using std::unique_ptr;
using std::shared_ptr;
using std::map;


#define COMMANDS 3
#define ALG_COUNT 3

#define BRUTE "brute"
#define GENETIC "genetic"
#define GREEDY "greedy"

bool parseCommand(int argc, char** argv, shared_ptr<int> n, string& datafile);
void cmdError();

int main(int argc, char** argv) {

    shared_ptr<int> limit = std::make_shared<int>();
    shared_ptr<int> processes = std::make_shared<int>(ALG_COUNT);
    string datafile;
    
    bool success = parseCommand(argc, argv, limit, datafile);
    shared_ptr<AGraphGen> graphGenerator = std::make_shared<AGraphGen>(datafile);
    

    if(success){
        //Initialise adjacency graph
        success = graphGenerator->initAdjacency();

        if(success){
            graphGenerator->printGraph();
            shared_ptr<int> n = std::make_shared<int>(0);
            
            //Initialise Algorithms
            unique_ptr<BruteForce> brute = std::make_unique<BruteForce>( processes, limit,  n, BRUTE);
            unique_ptr<FastOne> genetic = std::make_unique<FastOne>(processes, limit,  n, GENETIC);
            unique_ptr<FastTwo> greedy = std::make_unique<FastTwo>(processes, limit,  n, GREEDY);

            while(*processes) {
                //Add algorithms
            }
        }
        
        std::cout << "Experiment Complete" << std::endl;
    } else {
        cmdError();
    }

    return EXIT_SUCCESS;
}

bool parseCommand(int argc, char** argv, shared_ptr<int> limit, string& datafile){

    bool valid = true;
    if(argc == COMMANDS){
        try
        {
            *limit = std::stoi(argv[1]);
            valid = (*limit > 0);
            datafile = argv[2];
        }
        catch(const std::exception& e)
        {
            valid = false;
        } 
    }
    return valid;
}

void cmdError() {
    std::cout << 
    "Error Bad Arguement, Try:\n"
    "./ts <Time Limit> <datafile>\n"
    << std::endl; 
}