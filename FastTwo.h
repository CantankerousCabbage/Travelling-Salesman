#ifndef FASTTWO
#define FASTTWO

//Solution to TSP, implementatin using Greedy Algorithym, solution from:
//https://www.geeksforgeeks.org/travelling-salesman-problem-greedy-approach/
#include "Algorithm.h"

using std::map;
using std::cout;
using std::endl;

class FastTwo : public Algorithm {
    public:

    FastTwo(shared_ptr<int> processes, shared_ptr<int> limit, shared_ptr<int> n, string trialNum);
    ~FastTwo();

    /*
    * Calculates average turna around time
    */
    virtual int run();

    /*
    * Calculates average turna around time
    */
    void printResults();

    /*
    * -----Greedy Implementation------
    */

    void findMinRoute(vector<vector<int>> tsp);

};

#endif