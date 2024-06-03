#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <cmath>
#include <chrono>
#include "HashID.h"
#include "loadCSV_ID.h"
#include <thread>
using namespace std;
int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <numElementos>" << endl;
        return 1;
    }

    int inserts = stoi(argv[1]); // Tamaño de la tabla hash

    int N = 30000; // Tamaño de la tabla hash
    HashTable_ID ht_linear(N, linear_probing);


    // Medir tiempo de inserción en ht_linear
    auto start = chrono::high_resolution_clock::now();
    loadCSV_Id("universities_followers.csv", ht_linear, inserts);
    auto end = chrono::high_resolution_clock::now();
    auto duration_linear = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    // Imprimir duraciones
    cout <<inserts<< ";" << duration_linear << endl;


    return 0;
}