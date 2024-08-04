// https://contest.yandex.ru/contest/23815/run-report/99282749/

/*
--Principle of Operation--

The principle of the algorithm is described in the problem statement. 
Therefore, attention should be paid to the comparator.

The comparator first checks the number of solved problems. If the numbers 
are the same, it checks the penalties. If the penalties are equal, it 
lexicographically compares the names.

If the comparator returns true, the pointer is moved.

--Proof of Correctness--

An additional array for storing elements is not used => O(n^2) additional 
memory is not required.

--Time Complexity--

- In the best and average cases: O(n*log(n))
- In the worst case: O(n^2)

--Space Complexity--

- In the average case, when elements are roughly evenly divided at each step, 
the recursion depth will be proportional to the logarithm of the array size, i.e., 
O(log n). This is because an array of size n is divided into two roughly equal parts 
at each step.
- In the worst case, when each division results in one part containing n-1 elements and 
the other containing 0 (e.g., if the array is already sorted or if all elements are equal), 
the recursion depth will be O(n). This is because the recursive call will occur n times, with 
the size of the processed array decreasing by only 1 at each step.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Participant {
    string login;
    int problems_solved;
    int penalty;
};


bool compare_participants(const Participant& a, const Participant& b) {
    if (a.problems_solved != b.problems_solved) {
        return a.problems_solved > b.problems_solved;
    } 
    else if (a.penalty != b.penalty) {
        return a.penalty < b.penalty;
    }
    else {
        return a.login < b.login;
    }
}

void quick_sort(vector<Participant>& participants, int left, int right) {
    if (left >= right) {
        return;
    }

    Participant pivot = participants[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) { 
        while (compare_participants(participants[i], pivot)) {
            i++;
        }
        while (compare_participants(pivot, participants[j])) {
            j--;
        }

        if (i <= j) {
            swap(participants[i], participants[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quick_sort(participants, left, j);
    }
    if (i < right) {
        quick_sort(participants, i, right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<Participant> participants(n);

    for (int i = 0; i < n; i++) {
        cin >> participants[i].login >> participants[i].problems_solved >> participants[i].penalty;
    }

    quick_sort(participants, 0, n - 1);

    for (const auto& participant : participants) {
        cout << participant.login << endl;
    }
}
