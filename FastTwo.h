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

    FastTwo(shared_ptr<int> processes, shared_ptr<int> limit, shared_ptr<int> n, string trialName);
    ~FastTwo();

    /*
    * Calculates average turna around time
    */
    // virtual int run(int** graph);
    virtual int run(std::shared_ptr<vector<vector<int>>> graph);
    
    
    /*
    * -----Greedy Implementation------
    */

    // int TSP(int** tsp);
    int TSP(std::shared_ptr<vector<vector<int>>> tsp);

};

#endif