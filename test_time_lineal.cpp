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
    int seleccion =0;
    if (argc == 3) {
        int seleccion = stoi(argv[2]);
    }
    int N = 30000; // Tamaño de la tabla hash
    HashTable_ID ht_linear(N, linear_probing);


    // Medir tiempo de inserción en ht_linear
    auto start = chrono::high_resolution_clock::now();
    loadCSV_Id("universities_followers.csv", ht_linear, inserts);
    auto end = chrono::high_resolution_clock::now();
    auto duration_linear = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    // Imprimir duraciones
    if (seleccion==0){
        cout <<inserts<< ";" << duration_linear <<endl;
    }else if(seleccion==1){
        //search
        start = chrono::high_resolution_clock::now();
        ht_linear.search(31212312);
        ht_linear.search(414942137);
        ht_linear.search(465645);
        ht_linear.search(76536637);
        ht_linear.search(00000);
        end = chrono::high_resolution_clock::now();
        duration_linear = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        cout<<duration_linear<<endl;
    }else if(seleccion==2){
        //espacio usado
        cout<< ht_linear.sizeInBytes()<<endl;
    }else{
        cout<<"seleccion incorrecta";
    }


    return 0;
}