#ifndef FASTONE
#define FASTONE


//Solution TSP using Genetic Algorithm. From:
//https://www.geeksforgeeks.org/traveling-salesman-problem-using-genetic-algorithm/

#include "Algorithm.h"

#include <cmath>

using std::cout;
using std::endl;
using std::pow;

//------------------
// Number of cities in TSP
#define V 5
 
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
    virtual int run(int map[V][V]);

    /*
    * Calculates average turna around time
    */
    void printResults();

    /*
    * ----Genetic Library Algorithms---
    */

   /*
    *  Structure of a GNOME
    *   string defines the path traversed
    *   by the salesman while the fitness value
    *   of the path is stored in an integer
    */
    int rand_num(int start, int end);

    bool repeat(string s, char ch);

    /*
    * Function to return a mutated GNOME
    * Mutated GNOME is a string
    * with a random interchange
    * of two genes to create variation in species
    */
    string mutatedGene(string gnome);

    /*
    * Function to return a valid GNOME string
    * required to create the population
    */
    string create_gnome();

    /*Function to return the fitness value of a gnome.
    *The fitness value is the path length
    *of the path represented by the GNOME.
    */
    int cal_fitness(string gnome);

    // Function to return the updated value
    // of the cooling element.
    int cooldown(int temp);

    // Comparator for GNOME struct.
    bool lessthan(struct individual t1, struct individual t2);

    // Utility function for TSP problem.
    void TSPUtil(int map[V][V]);


};

#endif