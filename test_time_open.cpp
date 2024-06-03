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
    HashTable_open_ID ht_open(N);

    // Medir tiempo de inserción en ht_open
    auto start = chrono::high_resolution_clock::now();
    loadCSV_Id("universities_followers.csv", ht_open, inserts);
    auto end = chrono::high_resolution_clock::now();
    auto duration_open = chrono::duration_cast<chrono::nanoseconds>(end - start).count();


    // Imprimir duraciones

    cout <<inserts<< ";" << duration_open <<  endl;

    return 0;
}