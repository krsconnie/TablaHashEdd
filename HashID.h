#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <math.h>
#include <vector>
#include "twitterUsers.h"
using namespace std;
// Safe modulo function
int safe_modulo(int a, int b) {
    int result = a % b;
    return result >= 0 ? result : result + b;
}

// Hash functions
int h1(int k, int n) {
    return safe_modulo(k * 7939, n);
}

int h2(int k, int n) {
    float a = (float)k * 0.6180339887;
    a -= (int)a;
    return (int)(n * a);
}



// Probing methods
int linear_probing(int k, int n, int i) {
    return safe_modulo(h1(k, n) + i, n);
}

int quadratic_probing(int k, int n, int i) {
    return safe_modulo(h1(k, n) + i + 2 * i * i, n);
}

int double_hashing(int k, int n, int i) {
    return safe_modulo(h1(k, n) + i * (h2(k, n) + 1), n);
}

// Closed addressing hash table class
class HashTable_ID {
private:
    int size;
    vector<pair<long long int, twitterUser>> table;
    int (*hashing_method)(int, int, int);

public:
    HashTable_ID(int size, int (*hashing_method)(int, int, int))
        : size(size), hashing_method(hashing_method) {
        table.resize(size, make_pair(-1, twitterUser()));
    }

    void insert(long long int key, twitterUser user) {
        int i = 0;
        int index = hashing_method(key, size, i);
        while (table[index].first != -1) {
            i++;
            index = hashing_method(key, size, i);
            if (i >= size) {
                cout << "Hash table is full, cannot insert key: " << key << endl;
                return;
            }
        }
        table[index] = make_pair(key, user);
    }

    twitterUser* search(long long int key) {
        int i = 0;
        int index = hashing_method(key, size, i);
        while (table[index].first != key && table[index].first != -1) {
            i++;
            index = hashing_method(key, size, i);
            if (i >= size) {
                cout << "Key: " << key << " not found after full probing." << endl;
                return nullptr;
            }
        }
        if (table[index].first == -1) {
            return nullptr;
        }
        return &table[index].second;
    }
};

// Clase de tabla hash con direccionamiento abierto
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
        // cout << "Inserted key: " << key << " at index: " << index << " in open hash table" << endl;
    }

    twitterUser* search(long long int key) {
        int index = h1(key, size);
        for (auto& pair : table[index]) {
            if (pair.first == key) return &pair.second;
        }
        return nullptr;
    }
};
