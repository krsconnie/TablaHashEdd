#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <cmath>
#include <chrono>
#include "HashID.h"
#include "loadCSV_ID.h"

using namespace std;

#include <iostream>
#include "twitterUsers.h" // Include the header file containing the hash table implementations

int main() {

    // Create instances of hash tables
    HashTable_ID closedHashTable(100, linear_probing); // Closed addressing hash table using linear probing
    HashTable_open_ID openHashTable(100); // Open addressing hash table

    // Create some twitterUser objects
    twitterUser user1 = {"University A", "user1", "2022-01-01", 100, 500, 200, 123456};
    twitterUser user2 = {"University B", "user2", "2022-02-01", 150, 600, 250, 234567};
    twitterUser user3 = {"University C", "user3", "2022-03-01", 200, 700, 300, 345678};

    // Insert users into both hash tables
    closedHashTable.insert(user1.userId, user1);
    closedHashTable.insert(user2.userId, user2);
    closedHashTable.insert(user3.userId, user3);

    openHashTable.insert(user1.userId, user1);
    openHashTable.insert(user2.userId, user2);
    openHashTable.insert(user3.userId, user3);

    // Search for a user in both hash tables
    long long int searchKey = 234567;
    twitterUser* foundUserClosed = closedHashTable.search(searchKey);
    twitterUser* foundUserOpen = openHashTable.search(searchKey);

    // Check if the user was found and print their information
    if (foundUserClosed != nullptr) {
        std::cout << "User found in closed hash table: " << foundUserClosed->userName << std::endl;
    } else {
        std::cout << "User not found in closed hash table." << std::endl;
    }

    if (foundUserOpen != nullptr) {
        std::cout << "User found in open hash table: " << foundUserOpen->userName << std::endl;
    } else {
        std::cout << "User not found in open hash table." << std::endl;
    }

    return 0;
}
