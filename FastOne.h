#ifndef FASTONE
#define FASTONE

#include "Algorithm.h"

class FastOne : public Algorithm {
    public:

    FastOne();
    ~FastOne();

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