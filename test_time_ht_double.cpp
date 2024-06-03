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
    // Verificar si se proporcionan los argumentos correctos
    if (argc != 2 || argc !=3) {
        return 1;
    }
    int inserts = stoi(argv[1]); // Tamaño de la tabla hash
    // Verificar si se proporcionó un segundo argumento
    int seleccion =0;
    if (argc == 3) {
        int seleccion = stoi(argv[2]);
    }
    int N = 30000; // Tamaño de la tabla hash

    HashTable_ID ht_double(N, double_hashing);

    // Medir tiempo de inserción en ht_double
    auto start = chrono::high_resolution_clock::now();
    loadCSV_Id("universities_followers.csv", ht_double, inserts);
    auto end = chrono::high_resolution_clock::now();
    auto duration_double = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    // Imprimir duraciones de insercion
    if (seleccion==0){
        cout <<inserts<< ";" << duration_double <<endl;
    }else if(seleccion==1){
        //search 5 veces
        start = chrono::high_resolution_clock::now();
        ht_double.search(31212312);
        ht_double.search(414942137);
        ht_double.search(465645);
        ht_double.search(76536637);
        ht_double.search(00000);
        end = chrono::high_resolution_clock::now();
        duration_double = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        cout << duration_double <<endl;
    }else if(seleccion==2){
        //espacio usado
        cout<< ht_double.sizeInBytes()<<endl;
    }else{
        cout<<"seleccion incorrecta";
    }

    return 0;
}