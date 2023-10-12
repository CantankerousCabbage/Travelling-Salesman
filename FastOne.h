#ifndef FASTONE
#define FASTONE


//Solution TSP using Genetic Algorithm. From:
//https://gist.github.com/jgcoded/d7ecba7aa3e210419471

#include "Algorithm.h"

#include <cmath>
#include <vector>
#include <climits>

using std::cout;
using std::endl;
using std::pow;

//------------------
// Number of cities in TSP
// #define V 5
 
// Names of the cities
#define GENES ABCDE
 
// Starting Node Value
#define START 0
 
// Initial population size for the algorithm

#define POP_SIZE 10
//------------------

struct individual {
    string gnome;
    int fitness;
};

class FastOne : public Algorithm {
    public:

    FastOne(shared_ptr<int> processes, shared_ptr<int> limit, shared_ptr<int> n, string trialNum);
    ~FastOne();

    /*
    * Calculates average turna around time
    */
    virtual int run(int** map);


    // Utility function for TSP problem.
    int TSP(const vector<vector<int>>& cities, int pos, int visited, vector<vector<int>>& state);

    private:
        unsigned V;


};

#endif