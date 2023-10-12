#ifndef ALGORITHM
#define ALGORITHM

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <chrono>
#include <vector>
#include <map>

// #define V 4

using std::vector;
using std::string;
using std::unique_ptr;
using std::shared_ptr;
using std::chrono::system_clock;
using std::chrono::high_resolution_clock;

class Algorithm {
    public:

        Algorithm();
        Algorithm(shared_ptr<int> processes, shared_ptr<int> limit, shared_ptr<int> n, string trialNum);
        virtual ~Algorithm();

        /*
        * Run Algorithm till Limit reached
        */
        virtual int run();

        /*
        * Print results too terminal
        */
        void printResults();

        /*
        * Initiates Timer
        */
        void beginTimer();

        /*
        * Ends Timer
        */
        void endTimer();

        /*
        * Logs results to file
        */
        void logResults(double executionTime);

    protected:
        bool complete;
        shared_ptr<int> processes;
        shared_ptr<int> limit;
        shared_ptr<int> n;
        
    private: 
        
        std::chrono::time_point<high_resolution_clock> initial;
        std::ofstream outfile;
        string outName;
        // vector<string> archive;



};
#endif