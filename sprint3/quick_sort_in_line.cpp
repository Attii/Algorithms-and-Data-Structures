// https://contest.yandex.ru/contest/23815/run-report/99282749/

/*
--Принцип работы--

Принцип работы алгоритма описан в условии задачи. Так что стоит обратить 
внимание на компаратор. 

Компаратор в первую очередь проверяет количество решённых задач. Если 
количество одинаковое, то мы проверяем количество штрафов. Если 
штрафы равны, то лексиграфически сравниваем имена.

Если компаратор возвращает true, то двигаем указатель.

--Доказательство корректности--

Дополнительный массив для хранения элементов не используется => O(n^2) доп
памяти не требуется. 

--Временная сложность-- 

В лучшем и среднем случае: O(n*log(n))
В худшем случае: O(n^2)

--Пространственная сложность--

В среднем случае, когда элементы разделяются примерно поровну на каждом 
шаге, глубина рекурсии будет пропорциональна логарифму от размера массива, 
т.е. O(log n). Это объясняется тем, что массив размером n на каждом шаге 
делится на две примерно равные части.

В худшем случае, когда каждое разделение происходит так, что одна часть 
содержит n-1 элементов, а другая - 0 (например, если массив уже отсортирован 
или если все элементы равны), глубина рекурсии будет O(n). Это потому, 
что рекурсивный вызов будет происходить n раз, при этом на каждом шаге 
размер обрабатываемого массива уменьшается только на 1.
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
