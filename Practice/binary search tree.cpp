#include <iostream>
using namespace std;
struct Node {
  int value;
  Node* left;
  Node* right;

  Node(int val) : value(val), left(NULL), right(NULL) {}
};

class BinarySearchTree {
 public:
  BinarySearchTree() : root_(NULL) {}

  void Insert(int value) {
    Node* new_node = new Node(value);
    if (root_ == NULL) {
      root_ = new_node;
      return;
    }

    Node* current = root_;
    while (true) {
      if (value < current->value) {
        if (current->left == NULL) {
          current->left = new_node;
          return;
        }
        current = current->left;
      } else {
        if (current->right == NULL) {
          current->right = new_node;
          return;
        }
        current = current->right;
      }
    }
  }

  bool Find(int value) {
    Node* current = root_;
    while (current != NULL) {
      if (value == current->value) {
        return true;
      }
      if (value < current->value) {
        current = current->left;
      } else {
        current = current->right;
      }
    }
    return false;
  }

 private:
  Node* root_;
};

int main() {
  BinarySearchTree bst;
  bst.Insert(5);
  bst.Insert(3);
  bst.Insert(7);
  bst.Insert(2);
  bst.Insert(4);
  bst.Insert(6);
  bst.Insert(8);

  std::cout << bst.Find(3) << std::endl;
  std::cout << bst.Find(10) << std::endl;

  return 0;
}

