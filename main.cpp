
#include "BruteForce.h"
#include "FastOne.h"
#include "FastTwo.h"

#include <iostream>
#include <memory>
#include <map>

using std::string;
using std::unique_ptr;
using std::shared_ptr;
using std::map;

#define COMMANDS 2
#define ALG_COUNT 3

bool parseCommand(int argc, char** argv, shared_ptr<int> n);
void cmdError();

int main(int argc, char** argv) {

    shared_ptr<int> limit = std::make_shared<int>(limit);
    shared_ptr<int> processes = std::make_shared<int>(ALG_COUNT);
    bool success = parseCommand(argc, argv, limit);

    if(success){
        shared_ptr<int> n = std::make_shared<int>(n);

        while(*processes) {
            //Add algorithms
        }

        std::cout << "Experiment Complete" << std::endl;
    } else {
        cmdError();
    }

    return EXIT_SUCCESS;
}

bool parseCommand(int argc, char** argv, shared_ptr<int> limit){

    bool valid = true;
    if(argc == COMMANDS){
        try
        {
            *limit = std::stoi(argv[1]);
            valid = (*limit > 0); 
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
    "./ts <Time Limit>\n"
    << std::endl; 
}