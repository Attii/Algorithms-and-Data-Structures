//https://contest.yandex.ru/contest/25597/run-report/113834022/

/*
--Принцип работы--
Программа вычисляет расстояние Левенштейна между двумя строками s и t с 
использованием динамического программирования. Основная оптимизация 
заключается в использовании двух одномерных массивов (previous и current), 
которые хранят только текущие и предыдущие значения расстояния 
Левенштейна, вместо использования полной матрицы. В каждом шаге алгоритм 
обновляет значения current на основе previous и самого себя для соседних 
элементов, что позволяет определить минимальное количество операций для 
преобразования одной строки в другую.

--Доказательство корректности--
1) Инициализация: Массив previous корректно инициализируется для
представления стоимости преобразования пустой строки в подстроки t, что 
является базовым случаем динамического программирования.
2) Переход: Значения в current вычисляются на основе previous[j-1], 
previous[j], и current[j-1], которые представляют стоимость выполнения 
операций замены, вставки и удаления соответственно. Это гарантирует, что 
каждое значение current[j] содержит минимальное количество операций для 
достижения состояния s[0..i] к t[0..j].
3) Обновление: По завершении каждой итерации значения current становятся 
новым previous для следующей итерации, что гарантирует непрерывность 
вычислений.

--Временная сложность--
Временная сложность алгоритма составляет O(m*n), где m — длина строки s, 
а n — длина строки t. Эта сложность обусловлена двойным циклом, который 
перебирает все возможные подстроки s и t.

--Пространственная сложность--
Пространственная сложность сокращена до O(min(m,n)), благодаря 
использованию только двух одномерных массивов для хранения текущего и 
предыдущего состояний расчётов. 
*/

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>

using namespace std;

int levenstein_distance(const string &s, const string &t) {
    int m = s.length(), n = t.length();
    if (m < n) {
        return levenstein_distance(t, s);  // Убедимся, что n всегда меньше или равно m
    }

    vector<int> previous(n + 1), current(n + 1);

    // Инициализация для пустой строки s
    for (int j = 0; j <= n; ++j) {
        previous[j] = j;
    }

    for (int i = 1; i <= m; ++i) {
        current[0] = i;  // стоимость превращения строки s[0..i-1] в пустую строку t

        for (int j = 1; j <= n; ++j) {
            if (s[i-1] == t[j-1]) {
                current[j] = previous[j-1];  // символы совпадают, стоимость не увеличивается
            } else {
                current[j] = min({previous[j-1] + 1, previous[j] + 1, current[j-1] + 1});
            }
        }

        previous.swap(current);  // Перемещаем текущие значения в предыдущие для следующей итерации
    }

    return previous[n];
}

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);

    cout << levenstein_distance(s, t) << endl;

    return 0;
}