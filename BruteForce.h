#ifndef BRUTEFORCE
#define BRUTEFORCE

//Brute Force Implenetation in Run function from:
//https://www.geeksforgeeks.org/traveling-salesman-problem-tsp-implementation/

#include "Algorithm.h"
#include <bits/stdc++.h>

using std::min;



class BruteForce : public Algorithm {
    public:

    BruteForce(shared_ptr<int> processes, shared_ptr<int> limit, shared_ptr<int> n, string trialNum);
    ~BruteForce();

    /*
    * Calculates average turna around time
    */
    virtual int run(int graph[][V], int s);

    /*
    * Calculates average turna around time
    */
    void printResults();

    int travllingSalesmanProblem(int graph[][V], int s);


};

#endif
