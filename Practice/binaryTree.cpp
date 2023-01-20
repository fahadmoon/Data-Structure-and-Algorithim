// Binary Tree in C++

#include <stdlib.h>

#include <iostream>

using namespace std;

class node {
	public:
  int data;
   node *left;
   node *right;
};


class BinaryTree
{
	public:
		
// New node creation
  void Insert(int data) {
  node *newnode = new node;

  newnode->data = data;

  newnode->left = NULL;
  newnode->right = NULL;
  
}

// Traverse Preorder
void traversePreOrder(node *temp) {
  if (temp != NULL) {
    cout << " " << temp->data;
    traversePreOrder(temp->left);
    traversePreOrder(temp->right);
  }
}

// Traverse Inorder
void traverseInOrder(node *temp) {
  if (temp != NULL) {
    traverseInOrder(temp->left);
    cout << " " << temp->data;
    traverseInOrder(temp->right);
  }
}

// Traverse Postorder
void traversePostOrder(node *temp) {
  if (temp != NULL) {
    traversePostOrder(temp->left);
    traversePostOrder(temp->right);
    cout << " " << temp->data;
  }
}

};

int main() {
  node *root = node(1);
  root->left = node(2);
  root->right = node(3);
  root->left->left = node(4);

  cout << "preorder traversal: ";
  traversePreOrder(root);
  cout << "\nInorder traversal: ";
  traverseInOrder(root);
  cout << "\nPostorder traversal: ";
  traversePostOrder(root);
}
