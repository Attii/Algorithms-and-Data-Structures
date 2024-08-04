// https://contest.yandex.ru/contest/24414/run-report/101866296/

/*
--Principle of Operation--
Index Building: An index is created where each word is 
mapped to the documents in which it appears and the frequency 
of its occurrence in each document.
Query Processing: For each query, the relevance of documents is 
calculated based on the frequency of query words in the documents.

--Proof of Correctness--
Index: Correctly reflects the frequency of each word's 
occurrence in the documents.
Query Processing: Relevance is calculated correctly, considering 
the contribution of each unique word in the query.

--Time Complexity--
Index Building: O(nk), where n is the number of documents and k is 
the average number of words per document.
Query Processing: O(mq + mlog(m)), where m is the number of queries and 
q is the size of the query. The mq term reflects processing each query word 
against each document, and mlog(m) represents the complexity of sorting the results.

--Space Complexity--
Index: O(nk), depending on the number of unique words in the documents and 
their frequency of occurrence.
Query Processing: O(n), for storing the relevance of documents.
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
