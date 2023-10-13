#include "BruteForce.h"


BruteForce::BruteForce(shared_ptr<int> processes, shared_ptr<int> limit, shared_ptr<int> n, string trialNum) : Algorithm( processes, limit,  n, trialNum){
    //Initialise super
    
    // this->V = 0;
}
BruteForce::~BruteForce(){}

int BruteForce::run(std::shared_ptr<vector<vector<int>>> graph){
    
    if(!Algorithm::complete){
        
        int s = 0;
        std::cout << "Starting BruteForce..." << std::endl;
        this->beginTimer();
        Algorithm::shortest = TSP(graph, s);
        
        this->endTimer();
        this->printResults();
    }
    
    return complete;
}

int BruteForce::TSP(std::shared_ptr<vector<vector<int>>> graph, int s){
    vector<int> vertex;
    for (int i = 0; i < *n; i++){
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
            
            current_pathweight += (*graph)[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += (*graph)[k][s];
        
        // update minimum
        min_path = min(min_path, current_pathweight);
 
    } while (next_permutation(vertex.begin(), vertex.end()));
    
    
    return min_path;

}
