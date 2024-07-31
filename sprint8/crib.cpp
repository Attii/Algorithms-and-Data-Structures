//https://contest.yandex.ru/contest/26133/run-report/113861848/

/*
--Принцип работы--
Построение префиксного дерева (Trie):
-Программа начинается с создания Trie, где каждое слово из словаря 
добавляется в дерево. Каждый узел Trie содержит массив из 26 элементов 
(для каждой буквы алфавита) и флаг, указывающий на конец слова.

Динамическое программирование с использованием Trie:
-Используется массив dp, где dp[i] показывает, можно ли разделить 
подстроку s[0..i-1] на слова из словаря. Начальное значение dp[0] 
устанавливается в true, потому что пустая строка всегда разбивается 
тривиально.
-Для каждого индекса в строке s, программа проверяет все возможные 
продолжения подстроки, используя Trie для эффективного поиска, и 
обновляет dp в случае успешного нахождения слов.

--Доказательство корректности--
Корректность Trie:
-Trie корректно строится и каждое слово корректно добавляется. Конец 
каждого слова отмечается в Trie, что позволяет точно определить, 
заканчивается ли какая-либо подстрока словом из словаря.

Корректность использования dp:
-Если dp[i] истина, это значит, что подстрока s[0..i-1] может быть 
разделена. При нахождении валидного слова, начинающегося с позиции i и 
заканчивающегося на j, значение dp[j+1] устанавливается в true, что 
гарантирует, что любое разбиение, включающее это слово, будет корректным.

--Временная сложность--
-Построение Trie: O(W*L), где W - количество слов, L - средняя длина слова. 
Это время затрачивается на добавление каждого слова в Trie.

-Проверка разбиения строки: В худшем случае каждый символ строки 
проверяется на совпадение с началом слова из Trie, что может привести к 
проверке O(n^2) возможных подстрок в строке длиной n. Однако, 
использование Trie ускоряет проверку каждой подстроки.

--Пространственная сложность--
-Пространственная сложность Trie: В худшем случае, когда нет общих 
префиксов между словами, сложность может достигать O(W*L*A), где A - 
размер алфавита (26 для латинского алфавита).

-Массив dp: Пространственная сложность O(n), где n - длина строки.
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

struct TrieNode {
    vector<unique_ptr<TrieNode>> children;
    bool isEndOfWord;

    TrieNode() : children(26), isEndOfWord(false) {}
};

void insert(TrieNode* root, const string& key) {
    TrieNode* pCrawl = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = make_unique<TrieNode>();
        pCrawl = pCrawl->children[index].get();
    }
    pCrawl->isEndOfWord = true;
}

bool wordBreak(string s, TrieNode* root) {
    if (s.empty()) return true;
    int n = s.size();
    vector<bool> dp(n+1, false);
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        if (!dp[i]) continue;
        TrieNode* node = root;
        for (int j = i; j < n && node; j++) {
            int index = s[j] - 'a';
            node = node->children[index].get();
            if (node && node->isEndOfWord)
                dp[j+1] = true;
        }
    }
    return dp[n];
}

int main() {
    string T;
    cin >> T;
    int n;
    cin >> n;

    unique_ptr<TrieNode> root = make_unique<TrieNode>();
    string word;

    for (int i = 0; i < n; i++) {
        cin >> word;
        insert(root.get(), word);
    }

    cout << (wordBreak(T, root.get()) ? "YES" : "NO") << endl;

    return 0;
}

