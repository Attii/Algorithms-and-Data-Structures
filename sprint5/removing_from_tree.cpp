//https://contest.yandex.ru/contest/24810/run-report/112902165/

/*
--Principle of Operation--
The `remove` function deletes a node with the given key from a binary search tree (BST) 
while maintaining the BST properties. It recursively searches for the node with the key by 
comparing it with the root node. If the key is greater, the function moves to the right subtree; 
if it is smaller, it moves to the left subtree. Upon finding the node with the desired key, 
the function handles three cases:

1. Node with no left subtree (returns the right subtree).
2. Node with no right subtree (returns the left subtree).
3. Node with both subtrees (finds the maximum node in the left subtree, replaces the value of 
the node to be deleted with its value, and then recursively deletes the maximum node).

--Proof of Correctness--
The code correctly handles all cases of node deletion from the BST:
1. If the node has only one child, it can be safely removed by replacing it with that child.
2. If the node has two children, using the rightmost node from the left subtree ensures that all 
BST properties remain intact after deletion.

--Time Complexity--
In the worst case (degenerate tree, i.e., a list), deleting a node will have a complexity of O(n), 
where n is the number of nodes in the tree. In a balanced tree, the complexity will be O(log n) 
due to halving the number of nodes at each step of the recursion.

--Space Complexity--
Since the function uses recursion without storing additional data except for the recursive calls, 
the space complexity will be O(h), where h is the height of the tree. In the worst case, this can be 
O(n) for a degenerate tree, and O(log n) for a balanced tree.
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
