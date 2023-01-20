#include <iostream>
#include<string>
using namespace std;
struct Node {
    int value;
    Node* left;
    Node* right;

    Node()
    {
        value = 0;
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
    Node* getroot()
    {
        return root;
    }
    //Insert Element
    int Insert(Node* newnode, int element)
    {
        newnode = new Node;
        newnode->value = element;

        if (root == NULL)
        {
            root = newnode;
            return 0;
        }

        Node* current = root;
        while (true)
        {
            if (element < current->value)
            {
                if (current->left == NULL)
                {
                    current->left = newnode;
                    return 0;
                }
                current = current->left;
            }
            else if (element > current->value)
            {
                if (current->right == NULL)
                {
                    current->right = newnode;
                    return 0;

                }
                
                current = current->right;
            }
          
        }
    }

    //Traverse Inorder
    void traverseInOrder(Node* temp)
    {
        Node* temp1 = temp;
        Node* t =new Node ;
         /*   traverseInOrder(temp->left);
            cout << " " << temp->value;
            traverseInOrder(temp->right);*/
        while (temp1->left != NULL)
        {
            //cout << root->value;
           // cout << temp1->right->value;
            cout << temp1->left->value << " ";
            temp1 = temp1->left;
            
            if(temp1->left < temp1->left->value)
          

        }

        cout << root->value<<" ";

        while (temp->right!=NULL)
        {
                //cout << temp1->left->value;
                //cout << root->value;
                cout << temp->right->value<<" ";
                temp = temp->right;
              
        }
           
        
    }
};


int main()
{
    BinarySearchTree bst;
    
    bst.Insert(bst.getroot(), 5);
    bst.Insert(bst.getroot(), 10);
    bst.Insert(bst.getroot(), 2);
    bst.Insert(bst.getroot(), 1);
    bst.Insert(bst.getroot(), 9);
    bst.Insert(bst.getroot(), 8);
    bst.Insert(bst.getroot(), 11);
    bst.Insert(bst.getroot(), 15);

    bst.traverseInOrder(bst.getroot());
    cout << endl;

    return 0;
}

