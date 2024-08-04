// https://contest.yandex.ru/contest/23815/run-report/99984394/

/*
--Principle of Operation--

Before searching, we need to find the start and end of the broken array. 
For this, we have a function that finds the start and end using binary search. 
If the middle element of the array is less than the last element, then the start 
point is in the first half of the array, otherwise in the second half. This is 
because the transition point disrupts the sorting order.

Before running the function, we must check if the array is already sorted. This 
check is done by comparing the last element and the first element. If the first is 
less than the last, then the array is sorted.

Once the start and end of the array are found, we search for the desired element using 
binary search. Before this, we check if the desired element is less than the last element; 
if so, we search from the found start to the last element inclusively. Otherwise, we 
search from the first element to the found end inclusively. This is because the array is 
partially sorted, and thus we can directly search in the needed part of the array.

--Proof of Correctness--

Finding the start and end points takes O(log(n)) time because we are constantly searching 
in one half of the array until two elements are left. This is a modified binary search.

Finding the element also takes O(log(n)) time because we search for the element using 
binary search.

--Time Complexity--

As stated above.

--Space Complexity--

`bin_search` uses a loop, which requires O(1) additional memory.

The complexity of `find_end` is determined by the depth of the function call stack since 
it is recursive. `find_end` uses O(log(n)) additional memory, where n is the length of 
the array.
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
