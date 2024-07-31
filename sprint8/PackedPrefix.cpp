// https://contest.yandex.ru/contest/26133/run-report/113871893/

/*
--Принцип работы--
Программа состоит из двух основных функций: unpackString и 
longestCommonPrefix.

-unpackString: Эта функция обрабатывает входные строки в специально 
заданном формате сжатия, который включает в себя символы, повторения 
подстрок, и вложенные структуры. Используя стек для сохранения частей 
строки и повторений, функция последовательно собирает и расширяет сжатые 
подстроки при встрече с конструкциями вида n[A], где n — количество 
повторений, а A — подстрока.

-longestCommonPrefix: Функция определяет наибольший общий префикс между 
текущим префиксом и каждой новой распакованной строкой. Обновление 
префикса происходит посредством сравнения строк до первого несовпадения.

--Доказательство корректности--
-unpackString: Функция корректно обрабатывает различные случаи, включая 
вложенные и многократные повторения благодаря использованию стека для 
сохранения текущего состояния строки и количества повторений. Распаковка 
происходит корректно для каждой конструкции n[A] путем многократного 
добавления подстроки A к результату.

-longestCommonPrefix: Сравнение строк происходит до первого 
несовпадающего символа, что обеспечивает точное определение общего 
префикса. Префикс усекается только тогда, когда обнаруживается 
несовпадение, что предотвращает его некорректное укорачивание.

--Временная сложность--
-unpackString: Основной временной затратой является обработка каждого 
символа входной строки, что в наихудшем случае происходит за O(m), где m — 
длина распакованной строки. Однако, вложенные повторения могут привести к 
временной сложности до O(m^2) в худшем случае.

-longestCommonPrefix: Временная сложность этой функции составляет O(m), 
где m — длина наименьшей из двух сравниваемых строк. При вызове этой 
функции для каждой строки временная сложность в цикле будет O(n * m), 
где n — количество строк.

--Пространственная сложность--
-unpackString: Пространственная сложность зависит от использования стека 
для хранения частей строк и составляет O(m), где m — максимальная длина 
распакованной строки.

-longestCommonPrefix: Функция требует дополнительного пространства для 
хранения текущего префикса, которое в худшем случае равно O(m), где m — 
максимальная длина строки.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

string unpackString(const string &s) {
    stack<int> counts;
    stack<string> parts;
    string current;

    size_t i = 0;
    while (i < s.length()) {
        if (isdigit(s[i])) {
            int count = 0;
            while (i < s.length() && isdigit(s[i])) {
                count = count * 10 + (s[i] - '0');
                i++;
            }
            counts.push(count);
            parts.push(move(current));
            current.clear();
        } else if (s[i] == '[') {
            i++;
        } else if (s[i] == ']') {
            string temp = move(current);
            current = move(parts.top());
            parts.pop();
            int count = counts.top();
            counts.pop();
            for (int j = 0; j < count; j++) {
                current += temp;
            }
            i++;
        } else {
            current.push_back(s[i]);
            i++;
        }
    }

    return current;
}

string longestCommonPrefix(string &prefix, const string &s) {
    size_t minLength = min(prefix.size(), s.size());
    size_t i = 0;
    while (i < minLength && prefix[i] == s[i]) {
        i++;
    }
    return prefix.substr(0, i);
}

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << "" << endl;
        return 0;
    }

    string s, prefix;
    cin >> s;
    prefix = unpackString(s);

    for (int i = 1; i < n; i++) {
        cin >> s;
        string unpacked = unpackString(s);
        prefix = longestCommonPrefix(prefix, unpacked);
        if (prefix.empty()) break;
    }

    cout << prefix << endl;
    return 0;
}

