#ifndef FASTONE
#define FASTONE


//Solution TSP using Dynamic Algorithm. From:
//https://gist.github.com/jgcoded/d7ecba7aa3e210419471

#include "Algorithm.h"

#include <cmath>
#include <vector>
#include <climits>

using std::cout;
using std::endl;
using std::pow;

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
    virtual int run(std::shared_ptr<vector<vector<int>>> map);


    // Utility function for TSP problem.
    int TSP(const vector<vector<int>>* cities, int pos, int visited, vector<vector<int>>& state);

    private:
        unsigned V;


};

#endif