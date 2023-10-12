#include "AGraphGen.h"

AGraphGen::AGraphGen(string& datafile) : source{datafile} {
    graph = new int*[MAXGRAPH];

    for (int i = 0; i < MAXGRAPH; i++){
        graph[i] = new int[MAXGRAPH];
    }
    cout << "Graph Initialised" << endl;
};
AGraphGen::~AGraphGen(){
    
    if (graph != nullptr) {
        for (int i = 0; i < MAXGRAPH; i++) {
            delete[] graph[i]; 
        }
        delete[] graph;
    }
};

bool AGraphGen::initAdjacency(){
    infile.open(this->source);

    string line;
    string delimeter = " ";
    vector<vector <int>> coords(MAXGRAPH, vector<int>(2));
    vector<string> tokens;
    bool success = false;

    cout << "Begin Reading Data" << endl;
    if(infile.good()){
        try
        {
            //Get Vectors from file
            for(unsigned i = 0; i < MAXGRAPH; i++){
                std::getline(infile, line);
                splitString(line, tokens, delimeter);
                coords[i][0] = stoi(tokens[1]);
                coords[i][1] = stoi(tokens[2]);
            }
            
            //Caclulate adjacency graph
            for(unsigned i = 0; i < MAXGRAPH; i++){
                int x1 = coords[i][0];
                int y1 = coords[i][1];
                for(unsigned j = 0; j < MAXGRAPH; j++){
                    int x2 = coords[j][0];
                    int y2 = coords[j][1];
                    this->graph[i][j] = getDistance(x1, x2, y1, y2);
                };
            } 
            success = true;  
        }
        catch(const std::exception& e)
        {
           std::cout << "Error Generating Graph" << std::endl;
        }
    
    } else {
       std::cout << "Data file missing" << std::endl; 
    }
    return success;
};

int AGraphGen::getDistance(int x1,int x2, int y1, int y2){
    return
        sqrt( pow(x2- x1, 2) + pow(y2- y1, 2) );  
}

int** AGraphGen::fetchMatrix(int V){
    return graph;
};

void AGraphGen::splitString(string s, vector<string>& tokens, string delimeter)
{
    tokens.clear();
    char* _s = new char[s.length()+1];
    strcpy(_s, s.c_str());

    char * pch;
    pch = strtok (_s, delimeter.c_str());
    while (pch != NULL)
    {
        tokens.push_back(pch);
        pch = strtok (NULL, delimeter.c_str());
    }
    delete[] _s;
}

void AGraphGen::printGraph(){
    for(unsigned i = 0; i < MAXGRAPH; i++){
        cout << "{";
        for(unsigned j = 0; j < MAXGRAPH; j++){
            cout << " " << this->graph[i][j] << " ";
        }
       cout << "}\n"; 
    }
    cout << endl;
}