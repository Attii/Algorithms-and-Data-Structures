// https://contest.yandex.ru/contest/24414/run-report/101881488/

/*
--Принцип работы--
Программа реализует хеш-таблицу для хранения пар ключ-значение. Она 
оддерживает три основных операции: put, get, и delete. Хеш-таблица использует 
массив с цепочками (списками) для разрешения коллизий. Хеш-функция 
преобразует ключ в индекс массива, и цепочки используются для хранения элементов 
с одинаковым хешем.

Доказательство корректности
Хеш-Функция: Используя модульное деление и abs, функция гарантирует возврат 
корректного индекса массива, учитывая отрицательные ключи.
Обработка Коллизий: Цепочки обеспечивают правильное разрешение коллизий, 
позволяя хранить несколько элементов с одним хешем.

Временная сложность
put: В среднем O(1), но в худшем случае O(n), где n — количество элементов с одним хешем.
get: Аналогично put, O(1) в среднем, O(n) в худшем случае.
delete: Также O(1) в среднем и O(n) в худшем случае.
Хеш-Функция: Выполняется за O(1).

Пространственная сложность
Общая Пространственная Сложность: O(N), где N — максимальное количество 
элементов, которое может быть сохранено в хеш-таблице.
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
