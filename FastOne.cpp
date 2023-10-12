#include "FastOne.h"
#include "Algorithm.h"

FastOne::FastOne(shared_ptr<int> processes, shared_ptr<int> limit, shared_ptr<int> n,  string trialName) : Algorithm( processes, limit, n, trialName){}
FastOne::~FastOne(){}

int FastOne::run(int** map){
    
    if(!Algorithm::complete){

         vector<vector<int>> cities(*this->n, vector<int>(*this->n));

        for(int i = 0; i < *this->n; i++){
            for(int j = 0; j < *this->n; j++){
                cities[i][j] = (map[i][j] == 0) ? -1 : map[i][j];
            }
        }

        vector<vector<int>> state(cities.size());
        for(auto& neighbors : state)
        neighbors = vector<int>((1 << cities.size()) - 1, INT_MAX);

        std::cout << "Starting Genetic..." << std::endl;
        this->beginTimer();
        Algorithm::shortest = TSP(cities, 0, 1, state);
        this->endTimer();
        this->printResults();
        this->complete = Algorithm::complete;

    }

   return complete;
}


int FastOne::TSP(const vector<vector<int>>& cities, int pos, int visited, vector<vector<int>>& state)
{
    if(visited == ((1 << cities.size()) - 1))
        return cities[pos][0]; // return to starting city

    if(state[pos][visited] != INT_MAX)
        return state[pos][visited];

    for(int i = 0; i < (int)(cities.size()); ++i)
    {
        // can't visit ourselves unless we're ending & skip if already visited
        if(i == pos || (visited & (1 << i)))
            continue;

        int distance = cities[pos][i] + TSP(cities, i, visited | (1 << i), state);
        if(distance < state[pos][visited])
            state[pos][visited] = distance;
    }

    return state[pos][visited];
}
    