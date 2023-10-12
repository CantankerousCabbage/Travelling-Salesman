#include "BruteForce.h"


BruteForce::BruteForce(shared_ptr<int> processes, shared_ptr<int> limit, shared_ptr<int> n, string trialNum){
    //Initialise super
    Algorithm( processes, limit,  n, trialNum);
    this->V = 0;
}
BruteForce::~BruteForce(){}

int BruteForce::run(int** graph, int s){
    this->V = *this->n;

    // int graph[][V] = { { 0, 10, 15, 20 },
    //                    { 10, 0, 35, 25 },
    //                    { 15, 35, 0, 30 },
    //                    { 20, 25, 30, 0 } };
    // int s = 0;
    
    // travllingSalesmanProblem(graph, s);
    return complete;
}

int BruteForce::travllingSalesmanProblem(int** graph, int s){
    vector<int> vertex;
    for (int i = 0; i < V; i++){
        if (i != s){
             vertex.push_back(i);
        }      
    }
        
    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do {
 
        // store current Path weight(cost)
        int current_pathweight = 0;
 
        // compute current path weight
        int k = s;
        for (unsigned i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
 
        // update minimum
        min_path = min(min_path, current_pathweight);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;

}
