//https://contest.yandex.ru/contest/24810/run-report/112902165/

/*
--Принцип работы--
Функция remove удаляет узел с заданным ключом из бинарного дерева поиска, 
сохраняя свойства BST. Рекурсивно ищет узел с ключом, сравнивая его с 
корневым узлом. Если ключ больше, функция переходит к правому поддереву, 
если меньше — к левому. При нахождении узла с нужным ключом, функция 
обрабатывает три случая:

  1) Узел без левого поддерева (возвращается правое поддерево).
  2) Узел без правого поддерева (возвращается левое поддерево).
  3) Узел с обоими поддеревьями (находит максимальный узел в левом 
     поддереве и заменяет значение удаляемого узла на его значение, 
     после чего рекурсивно удаляет максимальный узел).


--Доказательство корректности--
Код корректно обрабатывает все случаи удаления узла из BST:
  1) Если узел имеет только одного ребенка, его можно безопасно удалить, 
  заменив его этим ребенком.
  2)Если у узла два ребенка, использование крайне правого узла из левого 
  поддерева гарантирует, что все свойства BST останутся в силе после 
  удаления.

--Временная сложность--
В худшем случае (вырожденное дерево, т.е. список) удаление узла будет 
иметь сложность O(n), где n — количество узлов в дереве. В 
сбалансированном дереве сложность будет O(log n) за счет деления 
количества узлов пополам на каждом шаге рекурсии.

--Пространственная сложность--
Так как функция использует рекурсию без хранения дополнительных данных, 
за исключением рекурсивных вызовов, пространственная сложность будет O(h),
где h — высота дерева. В худшем случае это может быть O(n) для 
вырожденного дерева, и O(log n) для сбалансированного дерева.
*/

#ifndef REMOTE_JUDGE
struct Node {  
  int value;  
  Node* left = nullptr;  
  Node* right = nullptr;
  Node(Node* left, Node* right, int value) : value(value), left(left), right(right) {}
};  
#endif
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif
#include <cassert>

Node* remove(Node* root, int key) {
    // Your code
    // “ヽ(´▽｀)ノ”
    if (root == nullptr) {
      return root;
    }

    if(key > root->value) {
      root->right = remove(root->right, key);
    } 
    else if (key < root->value){
      root->left = remove(root->left, key);
    }

    if (root->value == key) {

      if (root->left == nullptr) {
        return root->right;
      }

      if (root->right == nullptr) {
        return root->left;
      }
      
      Node* tmp = root->left;

      while (tmp->right != nullptr) tmp = tmp->right;

      root->value = tmp->value;

      root->left = remove(root->left, tmp->value);      

    }

    return root;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({nullptr, nullptr, 2});
    Node node2({&node1, nullptr, 3});
    Node node3({nullptr, &node2, 1});
    Node node4({nullptr, nullptr, 6});
    Node node5({&node4, nullptr, 8});
    Node node6({&node5, nullptr, 10});
    Node node7({&node3, &node6, 5});
    Node* newHead = remove(&node7, 10);
    assert(newHead->value == 5);
    assert(newHead->right == &node5);
    assert(newHead->right->value == 8);
}

int main() {
  test();
}
#endif