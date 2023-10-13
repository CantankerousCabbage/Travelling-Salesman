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
        // std::cout << "here2" << std::endl;
        // std::cout << "here1" << std::endl;
        // std::cout << "n" << *n << std::endl;
        // std::cout << "vertext" << vertex.size() << std::endl;
        for (unsigned i = 0; i < vertex.size(); i++) {
            // std::cout << "i: " << i << std::endl;
            // std::cout << "s:" << s << std::endl;
            current_pathweight += (*graph)[k][vertex[i]];
            k = vertex[i];
            // std::cout << "k:" << k << std::endl;
        }
        // std::cout << "done" << k << s << std::endl;
        // std::cout << "item" << (*graph)[k][s] << std::endl;
        current_pathweight += (*graph)[k][s];
        
        // update minimum
        min_path = min(min_path, current_pathweight);
 
    } while (next_permutation(vertex.begin(), vertex.end()));
    std::cout << "here3" << std::endl;
    
    return min_path;

}
