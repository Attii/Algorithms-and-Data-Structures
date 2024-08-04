// https://contest.yandex.ru/contest/24414/run-report/101881488/

/*
--Principle of Operation--
The program implements a hash table for storing key-value pairs. It supports three primary 
operations: put, get, and delete. The hash table uses an array with chaining (lists) for collision 
resolution. The hash function converts a key into an array index, and chains are used to store 
elements with the same hash.

--Proof of Correctness--
Hash Function: By using modular division and abs, the function ensures returning the correct array 
index, considering negative keys.
Collision Handling: Chaining provides proper collision resolution, allowing multiple elements with 
the same hash to be stored.

--Time Complexity--
- put: On average O(1), but in the worst case O(n), where n is the number of elements with the same hash.
- get: Similar to put, O(1) on average, O(n) in the worst case.
- delete: Also O(1) on average and O(n) in the worst case.
- Hash Function: Executes in O(1).

--Space Complexity--
- Total Space Complexity: O(N), where N is the maximum number of elements that can be stored in the hash table.
*/

#include <iostream>
#include <list>
#include <vector>

using namespace std;

const int HASH_SIZE = 100003; // Простое число для размера хеш-таблицы

struct HashTable {
    vector<list<pair<int, int>>> table;

    HashTable() : table(HASH_SIZE) {}

    int getHash(int key) {
        return abs(key % HASH_SIZE); 
    }

    void put(int key, int value) {
        int hash = getHash(key);
        auto &list = table[hash];
        for (auto &p : list) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        list.emplace_back(key, value);
    }

    void get(int key) {
        int hash = getHash(key);
        auto &list = table[hash];
        for (auto &p : list) {
            if (p.first == key) {
                cout << p.second << endl;
                return;
            }
        }
        cout << "None" << endl;
    }

    void deleteKey(int key) {
        int hash = getHash(key);
        auto &list = table[hash];
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (it->first == key) {
                cout << it->second << endl;
                list.erase(it);
                return;
            }
        }
        cout << "None" << endl;
    }
};

int main() {
    HashTable ht;
    int n, key, value;
    string command;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "put") {
            cin >> key >> value;
            ht.put(key, value);
        } else if (command == "get") {
            cin >> key;
            ht.get(key);
        } else if (command == "delete") {
            cin >> key;
            ht.deleteKey(key);
        }
    }
    return 0;
}
