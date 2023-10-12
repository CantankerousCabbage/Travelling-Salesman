#include "FastOne.h"

FastOne::FastOne(shared_ptr<int> processes, shared_ptr<int> limit, shared_ptr<int> n,  string trialName){
    Algorithm( processes, limit, n, trialName);
}
FastOne::~FastOne(){}

int FastOne::run( shared_ptr<int> n){
    // this->V = *n;
    // int map[V][V] = { { 0, 2, INT_MAX, 12, 5 },
    //                 { 2, 0, 4, 8, INT_MAX },
    //                 { INT_MAX, 4, 0, 3, 3 },
    //                 { 12, 8, 3, 0, 10 },
    //                 { 5, INT_MAX, 3, 10, 0 } };
//     int** map;
//    TSPUtil(map);
   return complete;
}

int FastOne::rand_num(int start, int end)
{
int r = end - start;
int rnum = start + rand() % r;
return rnum;
}
 
bool FastOne::repeat(string s, char ch)
{
    for (unsigned i = 0; i < s.size(); i++) {
        if (s[i] == ch)
            return true;
    }
    return false;
}
 
string FastOne::mutatedGene(string gnome)
{
    while (true) {
        int r = rand_num(1, V);
        int r1 = rand_num(1, V);
        if (r1 != r) {
            char temp = gnome[r];
            gnome[r] = gnome[r1];
            gnome[r1] = temp;
            break;
        }
    }
    return gnome;
}
 
string FastOne::create_gnome()
{
    string gnome = "0";
    while (true) {
        if (gnome.size() == V) {
            gnome += gnome[0];
            break;
        }
        int temp = rand_num(1, V);
        if (!repeat(gnome, (char)(temp + 48)))
            gnome += (char)(temp + 48);
    }
    return gnome;
}
 
int FastOne::cal_fitness(string gnome, int** map)
{
    // int map[V][V] = { { 0, 2, INT_MAX, 12, 5 },
    //                 { 2, 0, 4, 8, INT_MAX },
    //                 { INT_MAX, 4, 0, 3, 3 },
    //                 { 12, 8, 3, 0, 10 },
    //                 { 5, INT_MAX, 3, 10, 0 } };
    int f = 0;
    for (unsigned i = 0; i < gnome.size() - 1; i++) {
        if (map[gnome[i] - 48][gnome[i + 1] - 48] == INT_MAX)
            return INT_MAX;
        f += map[gnome[i] - 48][gnome[i + 1] - 48];
    }
    return f;
}
 
int FastOne::cooldown(int temp)
{
    return (90 * temp) / 100;
}
 
bool FastOne::lessthan(struct individual t1,
            struct individual t2)
{
    return t1.fitness < t2.fitness;
}
 
//  bool FastOne::lessthan(struct individual t1,
//             struct individual t2)
// {
//     return t1.fitness < t2.fitness;
// }

void FastOne::TSPUtil(int** map)
{
    // Generation Number
    int gen = 1;
    // Number of Gene Iterations
    int gen_thres = 5;
 
    vector<struct individual> population;
    struct individual temp;
 
    // Populating the GNOME pool.
    for (int i = 0; i < POP_SIZE; i++) {
        temp.gnome = create_gnome();
        temp.fitness = cal_fitness(temp.gnome, map);
        population.push_back(temp);
    }
 
    cout << "\nInitial population: " << endl
        << "GNOME     FITNESS VALUE\n";
    for (int i = 0; i < POP_SIZE; i++)
        cout << population[i].gnome << " "
            << population[i].fitness << endl;
    cout << "\n";
 
    // bool found = false;
    int temperature = 10000;
    
    auto lessthan = [](struct individual t1,
            struct individual t2){
           return t1.fitness < t2.fitness;     
    };
    // Iteration to perform
    // population crossing and gene mutation.
    while (temperature > 1000 && gen <= gen_thres) {
        sort(population.begin(), population.end(), lessthan);
        cout << "\nCurrent temp: " << temperature << "\n";
        vector<struct individual> new_population;
 
        for (int i = 0; i < POP_SIZE; i++) {
            struct individual p1 = population[i];
 
            while (true) {
                string new_g = mutatedGene(p1.gnome);
                struct individual new_gnome;
                new_gnome.gnome = new_g;
                new_gnome.fitness = cal_fitness(new_gnome.gnome, map);
 
                if (new_gnome.fitness <= population[i].fitness) {
                    new_population.push_back(new_gnome);
                    break;
                }
                else {
 
                    // Accepting the rejected children at
                    // a possible probability above threshold.
                    float prob = pow(2.7,
                                    -1 * ((float)(new_gnome.fitness
                                                - population[i].fitness)
                                        / temperature));
                    if (prob > 0.5) {
                        new_population.push_back(new_gnome);
                        break;
                    }
                }
            }
        }
 
        temperature = cooldown(temperature);
        population = new_population;
        cout << "Generation " << gen << " \n";
        cout << "GNOME     FITNESS VALUE\n";
 
        for (int i = 0; i < POP_SIZE; i++)
            cout << population[i].gnome << " "
                << population[i].fitness << endl;
        gen++;
    }
}