#ifndef AGRAPHGEN
#define AGRAPHGEN

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <string.h>
#include <cmath>
#include <memory>

#define MAXGRAPH 30

using std::vector;
using std::string;
using std::cout;
using std::endl;


class AGraphGen {
    public:
        AGraphGen(string& datafile);
        ~AGraphGen();

        void splitString(std::string s, std::vector<std::string>& tokens, std::string delimeter);

        /*
        * Calculate distance between two vectors
        */
        int getDistance(int x1,int x2, int y1, int y2);

        /*
        * Build adjacency matrix from vectors
        */
        bool initAdjacency();

        /*
        * fetch matrix 
        */
        // int** fetchMatrix();
        std::shared_ptr<vector<vector<int>>> fetchMatrix();

        void printGraph();

        

    private:
        string source;
        std::ifstream infile;
        // int** graph;
        vector<vector<int>> g;
        std::shared_ptr<vector<vector<int>>> graph;

};


#endif