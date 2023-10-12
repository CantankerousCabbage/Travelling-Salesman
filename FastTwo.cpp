#include "FastTwo.h"
#include "AGraphGen.h"
#include "Algorithm.h"


FastTwo::FastTwo(shared_ptr<int> processes, shared_ptr<int> limit, shared_ptr<int> n, string trialName) : Algorithm(processes,  limit, n, trialName) {
    
}
FastTwo::~FastTwo(){};

/*
* Calculates average turna around time
*/
int FastTwo::run(int** map){
    
    if(!Algorithm::complete){
        std::cout << "Starting Greedy..." << std::endl;
         vector<vector<int>> tsp(*this->n, vector<int>(*this->n));

        for(int i = 0; i < *this->n; i++){
            for(int j = 0; j < *this->n; j++){
                tsp[i][j] = (map[i][j] == 0) ? -1 : map[i][j];
            }
        }
    
        this->beginTimer();
        Algorithm::shortest = TSP(tsp);
        this->endTimer();
        this->printResults();
        
    }
    
    return complete;
};

// Function to find the minimum
// cost path for all the paths
int FastTwo::TSP(vector<vector<int>> tsp)
{
    int sum = 0;
    unsigned counter = 0;
    unsigned j = 0, i = 0;
    int min = INT_MAX;
    map<int, int> visitedRouteList;
 
    // Starting from the 0th indexed
    // city i.e., the first city
    visitedRouteList[0] = 1;
    int route[tsp.size()];
 
    // Traverse the adjacency
    // matrix tsp[][]
    while (i < tsp.size() && j < tsp[i].size())
    {
 
        // Corner of the Matrix
        if (counter >= tsp[i].size() - 1)
        {
            break;
        }
 
        // If this path is unvisited then
        // and if the cost is less then
        // update the cost
        if (j != i && (visitedRouteList[j] == 0))
        {
            if (tsp[i][j] < min)
            {
                min = tsp[i][j];
                route[counter] = j + 1;
            }
        }
        j++;
 
        // Check all paths from the
        // ith indexed city
        if (j == tsp[i].size())
        {
            sum += min;
            min = INT_MAX;
            visitedRouteList[route[counter] - 1] = 1;
            j = 0;
            i = route[counter] - 1;
            counter++;
        }
    }
 
    // Update the ending city in array
    // from city which was last visited
    i = route[counter - 1] - 1;
 
    for (j = 0; j < tsp.size(); j++)
    {
 
        if ((i != j) && tsp[i][j] < min) 
        {
            min = tsp[i][j];
            route[counter] = j + 1;
        }
    }
    sum += min;
    return (sum);
 
}