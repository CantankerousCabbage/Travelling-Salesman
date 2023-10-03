#ifndef BRUTEFORCE
#define BRUTEFORCE

#include "Algorithm.h"

class BruteForce : public Algorithm {
    public:

    BruteForce();
    ~BruteForce();

    /*
    * Calculates average turna around time
    */
    virtual void run();

    /*
    * Calculates average turna around time
    */
    void printResults();


};

#endif
