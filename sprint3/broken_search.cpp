// https://contest.yandex.ru/contest/23815/run-report/99984394/

/*
--Принцип работы--

Перед поиском мы должны найти начало и конец сломанного массива. Для 
этого у нас есть функция, где мы ищем начало и конец с помощью бинарного 
поиска. Если средний элемент массива меньше последнего элемента, то пара 
начало старт находится в первой половине массива, иначе во второй половине. 
Это связано с тем, что переходный момент нарушает сортировку. 

Перед запуском функции надо обязательно проверить, не является ли массив 
отсортированным. Проверка происходит путем сравнения последнего элемента 
и первого. Если первый меньше последнего, то значит сортировка не нарушена.

После того, как найдены начало и конец массива, с помощью бинарного поиска 
ищем нужный элемент. Перед этим проверяем, если искомый элемент меньше 
последнего, то ищем от найденного начало до последнего элемента включительно, 
иначе ищем от первого элемента до найденного конца, включительно. Связано 
это с тем, что массив частично отсортирован и благодаря этому мы можем 
искать сразу в нужной нам части массива.

--Доказательство корректности--

Поиска начало и конца происходит за время О(log(n)), так как мы ищем 
постоянно в одной половине массива, пока не останется два элемента. 
Модифицированный бинарный поиск. 

Поиск элемента происходит тоже за О(log(n)), так как мы ищем элемент с 
помощью бинарного поиска.

--Временная сложность--

Смотреть выше.

--Пространственная сложность--

bin_search использует цикл, что требует O(1) доп памяти. 

Сложность find_end определяется глубиной стека вызова функции, 
так как она является рекурсивной. find_end использует O(log(n)) 
доп памяти, где n длина массива.
*/


//#include "solution.h"
#include <vector>
#include <cassert>

#include <iostream>
using namespace std;

void fill_int_vector(vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    
}

int bin_search(const std::vector<int>& arr, int x, int left, int right) {
    while (left < right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] > x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int find_end(const std::vector<int>& arr, int left, int right) {
    if (right - left < 2) {
        return right;
    }

    int mid = (left + right) / 2;

    if (arr[mid] < arr[right]) {
        return find_end(arr, left, mid);
    } 
    else {
        return find_end(arr, mid, right);
    }
}
 
int broken_search(const std::vector<int>& vec, int k) {
    if (vec[0] < vec[vec.size()-1]) {
        return bin_search(vec, k, 0, vec.size());
    } 
    else {
        int end = find_end(vec, 0, vec.size() - 1);

        if (k > vec.back()) {
            return bin_search(vec, k, 0, end);
        } 
        else {
            return bin_search(vec, k, end, vec.size());
        }
    }
}

void test() {
    std::vector<int> arr = {19, 21, 100, 101, 1, 4, 5, 7, 12};
    assert(6 == broken_search(arr, 5));
}

int main() {
    int n, k;
    
    cin >> n >> k;
    std::vector<int> arr(n);
    fill_int_vector(arr);
    
    cout << broken_search(arr, k) << endl;
}