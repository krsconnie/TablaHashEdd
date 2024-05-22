#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <math.h>
#include <vector>
using namespace std;



int h1(int k, int n) {
  return (k*7)%n;
}
int h2(int k, int n) {
  float a = (float)k* 0.6180339887;
  a -= (int)a;
  
  return n*a;
}
int linear_probing(int k, int n, int i) {
  return (h1(k, n) + i) % n;
}
int quadratic_probing(int k, int n, int i) {
  return (h1(k, n) + i + 2*i*i) % n;
}
int double_hashing(int k, int n, int i) {
  return (h1(k, n) + i*(h2(k, n)+1)) % n;
}

struct HashTable {
  int size;
  int* table;
  int (*hashing_method)(int, int, int);

  HashTable(int size, int (*hashing_method)(int, int, int)) : size(size), hashing_method(hashing_method) {
    table = new int[size];
    for (int i = 0; i < size; i++) {
      table[i] = -1;
    }
  }

  void insert(int key) {
    int i = 0;
    while (table[hashing_method(key, size, i)] != -1) {
      i++;
    }
    table[hashing_method(key, size, i)] = key;
  }

  int* search(int key) {
    int i = 0;
    while (table[hashing_method(key, size, i)] != key && table[hashing_method(key, size, i)] != -1) {
      i++;
    }
    if (table[hashing_method(key, size, i)] == -1) {
      return nullptr; // Si no se encontró el valor
    }
    return &table[hashing_method(key, size, i)];
  }
};



struct HashTable_open {
  int size;
  vector<list<int>> table;

  HashTable_open(int size) : size(size) {
    table.resize(size);
  }

  void insert(int key) {
    int index = h1(key, size);
    table[index].push_back(key);
  }

  int* search(int key) {
    int index = h1(key, size);
    for (int k : table[index]) {
      if (k == key) return &key;
    }
    return nullptr;
  }
};