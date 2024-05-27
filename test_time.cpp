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
    HashTable_ID ht_quadratic(N, quadratic_probing);
    HashTable_ID ht_double(N, double_hashing);
    HashTable_open_ID ht_open(N);

    // Medir tiempo de inserción en ht_linear
    auto start = chrono::high_resolution_clock::now();
    loadCSV_Id("universities_followers.csv", ht_linear, inserts);
    auto end = chrono::high_resolution_clock::now();
    auto duration_linear = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    // Medir tiempo de inserción en ht_quadratic
    start = chrono::high_resolution_clock::now();
    loadCSV_Id("universities_followers.csv", ht_quadratic, inserts);
    end = chrono::high_resolution_clock::now();
    auto duration_quadratic = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    // Medir tiempo de inserción en ht_double
    start = chrono::high_resolution_clock::now();
    loadCSV_Id("universities_followers.csv", ht_double, inserts);
    end = chrono::high_resolution_clock::now();
    auto duration_double = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    // Medir tiempo de inserción en ht_open
    start = chrono::high_resolution_clock::now();
    loadCSV_Id("universities_followers.csv", ht_open, inserts);
    end = chrono::high_resolution_clock::now();
    auto duration_open = chrono::duration_cast<chrono::nanoseconds>(end - start).count();


    // Imprimir duraciones
    cout << "ht_linear;" <<inserts<< ";" << duration_linear << endl;
    cout << "ht_quadratic;" <<inserts<< ";" << duration_quadratic << endl;
    cout << "ht_double;" <<inserts<< ";" << duration_double <<endl;
    cout << "ht_open;" <<inserts<< ";" << duration_open <<  endl;

    return 0;
}