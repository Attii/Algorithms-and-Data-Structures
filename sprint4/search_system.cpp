// https://contest.yandex.ru/contest/24414/run-report/101866296/

/*
--Принцип работы--
Построение индекса: Создается индекс, где каждому слову сопоставляются 
документы, в которых оно встречается, и частота вхождения в каждый документ.
Обработка запросов: Для каждого запроса подсчитывается релевантность 
документов на основе количества вхождений слов запроса в документы.

--Доказательство корректности--
Индекс: Корректно отображает частоту вхождения каждого слова в документы.
Обработка запросов: Релевантность рассчитывается правильно, учитывая вклад 
каждого уникального слова в запросе.

--Временная сложность--
Построение индекса: O(nk), где n - количество документов, k - среднее количество слов.
Обработка запросов: O(mq+mlog(m)), где где m - количество запросов, 
q - размер запроса, то mq отражает обработку каждого слова запроса по 
отношению к каждому документу, а mlog(m) — сложность сортировки результатов. 

--Пространственная сложность--
Индекс: O(nk), зависит от количества уникальных слов в документах и их 
частоты встречаемости.
Обработка запросов: O(n), для хранения релевантности документов.
*/



#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<string> split(const string &str) {
    vector<string> tokens;
    string token;
    for (char ch : str) {
        if (ch == ' ') {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token += ch;
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    // Создаем индекс: слово : (номер документа : количество вхождений)
    unordered_map<string, unordered_map<int, int>> index;

    for (int i = 0; i < n; ++i) {
        string document;
        getline(cin, document);
        vector<string> words = split(document);

        for (const string &word : words) {
            // Сдвигаем индекс на 1, чтобы соответствовать условию задачи
            index[word][i + 1]++;
        }
    }

    int m;
    cin >> m;
    cin.ignore();

    for (int i = 0; i < m; ++i) {
        string query;
        getline(cin, query);
        vector<string> words = split(query);

        unordered_map<int, int> relevance;
        set<string> unique_words(words.begin(), words.end()); 

        for (const string &word : unique_words) {
            if (index.find(word) != index.end()) {
                for (const auto &entry : index[word]) {
                    relevance[entry.first] += entry.second;
                }
            }
        }

        vector<pair<int, int>> docs(relevance.begin(), relevance.end());

        sort(docs.begin(), docs.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        });

        for (int j = 0; j < min(5, static_cast<int>(docs.size())); ++j) {
            if (j > 0) cout << " ";
            cout << docs[j].first; 
        }
        cout << endl;
    }

    return 0;
}
