#include "FastTwo.h"
#include "AGraphGen.h"
#include "Algorithm.h"


FastTwo::FastTwo(shared_ptr<int> processes, shared_ptr<int> limit, shared_ptr<int> n, string trialName) : Algorithm(processes,  limit, n, trialName) {
    
}
FastTwo::~FastTwo(){};

/*
* Calculates average turna around time
*/
// int FastTwo::run(int** tsp){
    
//     if(!Algorithm::complete){
       
//         this->beginTimer();
//         Algorithm::shortest = TSP(tsp);
//         this->endTimer();
//         this->printResults();
        
//     }
    
//     return complete;
// };

int FastTwo::run(std::shared_ptr<vector<vector<int>>> tsp){
    
    if(!Algorithm::complete){
       
        this->beginTimer();
        Algorithm::shortest = TSP(tsp);
        this->endTimer();
        this->printResults();
        
    }
    
    return complete;
};

// Function to find the minimum
// cost path for all the paths
int FastTwo::TSP(std::shared_ptr<vector<vector<int>>> tsp)
{
    int sum = 0;
    int counter = 0;
    int j = 0, i = 0;
    int min = INT_MAX;
    map<int, int> visitedRouteList;
 
    // Starting from the 0th indexed
    // city i.e., the first city
    visitedRouteList[0] = 1;
    int route[*n];
    
    // Traverse the adjacency
    // matrix tsp[][]
    while (i < *n)
    {
 
        // Corner of the Matrix
        if (counter >= *n - 1)
        {
            break;
        }
 
        // If this path is unvisited then
        // and if the cost is less then
        // update the cost
        if (j != i && (visitedRouteList[j] == 0))
        {

            if ((*tsp)[i][j] < min)
            {
                min = (*tsp)[i][j];
                route[counter] = j + 1;
            }
        }
        j++;
 
        // Check all paths from the
        // ith indexed city
        if (j == *n)
        {
             std::cout << " N: " << i << "Min: " << min << std::endl;
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
    
        min = (*tsp)[i][j];
    std::cout << "Selected" << min << std::endl;
    sum += min;
    return (sum);
 
}