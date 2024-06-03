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
    HashTable_open_ID ht_open(N);

    // Medir tiempo de inserción en ht_open
    auto start = chrono::high_resolution_clock::now();
    loadCSV_Id("universities_followers.csv", ht_open, inserts);
    auto end = chrono::high_resolution_clock::now();
    auto duration_open = chrono::duration_cast<chrono::nanoseconds>(end - start).count();


    // Imprimir duraciones
    if (seleccion==0){
        cout <<inserts<< ";" << duration_open <<endl;
    }else if(seleccion==1){
        //search
        start = chrono::high_resolution_clock::now();
        ht_open.search(31212312);
        ht_open.search(414942137);
        ht_open.search(465645);
        ht_open.search(76536637);
        ht_open.search(00000);
        end = chrono::high_resolution_clock::now();
        duration_open = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        cout<<duration_open<<endl;
    }else if(seleccion==2){
        //espacio usado
        cout<< ht_open.sizeInBytes()<<endl;
    }else{
        cout<<"seleccion incorrecta";
    }

    return 0;
}