#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree {
private:
    Node* root;
public:
    BinarySearchTree()
    {
        root = NULL;
    } 

    void Insert(int value) 
    {
        Node* new_node = new Node(value);
        if (root == NULL) 
        {
            root = new_node;
            return;
        }

        Node* current = root;
        while (true) 
        {
            if (value < current->value) 
            {
                if (current->left == NULL) 
                {
                    current->left = new_node;
                    return;
                }
                current = current->left;
            }
            else
            {
                if (current->right == NULL)
                {
                    current->right = new_node;
                    return;
                }
                current = current->right;
            }
        }
    }

    bool Find(int value) {
        Node* current = root;
        while (current != NULL)
        {
            if (value == current->value) 
            {
                return true;
            }
            if (value < current->value) 
            {
                current = current->left;
            }
            else 
            {
                current = current->right;
            }
        }
        return false;
    }
    
    void Delete(int value) {
  // Find the node to be deleted.
  Node* current = root;
  Node* parent = NULL;
  while (current != NULL && current->value != value)
  {
    parent = current;
    if (value < current->value) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  if (current == NULL)
  {

    cout<<"Node not found"<<endl;
    return;
  }

  // Determine the number of children of the node to be deleted.
  if (current->left == NULL || current->right == NULL) {
    // One child
    Node* child = (current->left != NULL) ? current->left : current->right;
    if (parent == NULL) {
      // Node to be deleted is the root.
      root= child;
    } else {
      if (parent->left == current) {
        parent->left = child;
      } else {
        parent->right = child;
      }
    }
    cout<<current->value<<endl;
    delete current;
  } 
  else
  {
    // Two children
    // Find the successor.
    Node* successor = current->right;
    Node* successor_parent = current;
    while (successor->left != NULL) {
      successor_parent = successor;
      successor = successor->left;
    }
    // Replace the node to be deleted with the successor.
    current->value = successor->value;
    // Delete the successor.
    if (successor_parent->left == successor) {
      successor_parent->left = successor->right;
    } else {
      successor_parent->right = successor->right;
    }
    cout<<successor->value<<endl;
    delete successor;
  }
}



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

    cout << bst.Find(3) << endl;
    cout << bst.Find(10) << endl;
    bst.Delete(11);

    return 0;
}

