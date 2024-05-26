#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <cmath>
#include <chrono>
#include "HashID.h"
#include "loadCSV_ID.h"

using namespace std;
int main(int argc, char* argv[]) {
    int N = stoi(argv[1]); // Tamaño de la tabla hash
    HashTable_ID ht_linear(N, linear_probing);
    HashTable_ID ht_quadratic(N, quadratic_probing);
    HashTable_ID ht_double(N, double_hashing);
    HashTable_open_ID ht_open(N);

    // Medir tiempo de inserción en ht_linear
    auto start = chrono::high_resolution_clock::now();
    loadCSV_Id("universities_followers.csv", ht_linear, N);
    auto end = chrono::high_resolution_clock::now();
    auto duration_linear = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    // Medir tiempo de inserción en ht_quadratic
    start = chrono::high_resolution_clock::now();
    loadCSV_Id("universities_followers.csv", ht_quadratic, N);
    end = chrono::high_resolution_clock::now();
    auto duration_quadratic = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    // Medir tiempo de inserción en ht_double
    start = chrono::high_resolution_clock::now();
    loadCSV_Id("universities_followers.csv", ht_double, N);
    end = chrono::high_resolution_clock::now();
    auto duration_double = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    // Medir tiempo de inserción en ht_open
    start = chrono::high_resolution_clock::now();
    loadCSV_Id("universities_followers.csv", ht_open, N);
    end = chrono::high_resolution_clock::now();
    auto duration_open = chrono::duration_cast<chrono::nanoseconds>(end - start).count();


    // Imprimir duraciones
    cout << "ht_linear;" <<argc<< ";" << duration_linear << endl;
    cout << "ht_quadratic;" <<argc<< ";" << duration_quadratic << endl;
    cout << "ht_double;" <<argc<< ";" << duration_double <<endl;
    cout << "ht_open;" <<argc<< ";" << duration_open <<  endl;

    return 0;
}