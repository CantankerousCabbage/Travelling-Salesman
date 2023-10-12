#include "Algorithm.h"

Algorithm::Algorithm(){};
Algorithm::Algorithm(shared_ptr<int> processes, shared_ptr<int> limit, shared_ptr<int> n, string trialName) 
: processes{processes}, limit{limit}, n{n} {
    this->outName = "Trial " + trialName + ".txt";
    this->complete = false;

    outfile.open(this->outName, std::ios_base::app);
}

Algorithm::~Algorithm(){
};

void Algorithm::printResults(){
    std::cout << "Run: " << *(this->n) << ", Time:  " << time << "sec,  " << this->complete << std::endl;
};

void Algorithm::beginTimer(){
    this->initial = high_resolution_clock::now();
};

void Algorithm::endTimer(){
    std::chrono::duration<double> timeSeconds = (high_resolution_clock::now() - this->initial);
    double executionTime = (double)timeSeconds.count();
    this->time = executionTime;
    logResults(executionTime);
};

void Algorithm::logResults(double executionTime){
    this->complete = (executionTime <= *limit) ? false : true; 
    this->outfile << *(this->n) << " " << executionTime << " " << this->complete << " " << this->shortest << "\n";
    if(complete){
        *processes -= 1;
        std::cout << "COMPLETE" << std::endl;
    }
};


int Algorithm::run(){
    return complete;
};