#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <math.h>
#include <vector>
#include "twitterUsers.h"
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
class HashTable_ID {
private:
    int size;
    vector<pair<long long int, twitterUser>> table;
    int (*hashing_method)(int, int, int);

public:
    HashTable_ID(int size, int (*hashing_method)(int, int, int))
        : size(size), hashing_method(hashing_method) {
        table.resize(size, make_pair(-1, twitterUser())); // Initialize table with pairs of -1 and default constructed twitterUser
    }

    void insert(long long int key, twitterUser user) {
        int i = 0;
        while (table[hashing_method(key, size, i)].first != -1) {
            i++;
        }
        table[hashing_method(key, size, i)] = make_pair(key, user);
    }

    twitterUser* search(long long int key) {
        int i = 0;
        while (table[hashing_method(key, size, i)].first != key && table[hashing_method(key, size, i)].first != -1) {
            i++;
        }
        if (table[hashing_method(key, size, i)].first == -1) {
            return nullptr; // Si no se encontró el valor
        }
        return &table[hashing_method(key, size, i)].second;
    }
};

class HashTable_open_ID {
private:
    int size;
    vector<list<pair<long long int, twitterUser>>> table;

public:
    HashTable_open_ID(int size) : size(size) {
        table.resize(size);
    }

    void insert(long long int key, twitterUser user) {
        int index = h1(key, size);
        table[index].push_back(make_pair(key, user));
    }

    twitterUser* search(long long int key) {
        int index = h1(key, size);
        for (auto& pair : table[index]) {
            if (pair.first == key) return &pair.second;
        }
        return nullptr;
    }
};