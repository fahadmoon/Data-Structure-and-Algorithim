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

class LeafNode {
private:
    Node* root;
public:
    
    LeafNode()
    {
        root = NULL;
    } 
    Node* getroot()
    {
    	return root;
	}
    //Insert Element
    int Insert(Node* newnode,int element) 
    {
        newnode = new Node;
        newnode->value=element;
        
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
            else
            {
                if (current->right == NULL)
                {
                    current->right = newnode;
                     return 0;
                    
                }
                current = current->right;
            }
        }
        
        
        //
    }
    //Middle 
    void Middle(Node *temp)
    {
    	int arr[10];
    	int i=0;
    	if (temp != NULL) 
		{
			
    	Middle(temp->left);
    	arr[i++]=temp->value;
    	Middle(temp->right);
		
		}
		
    
    
	}
    //Traverse Inorder
    void traverseInOrder(Node* temp) 
	{       
        if (temp != NULL) 
		{
            traverseInOrder(temp->left);
            cout << " " << temp->value;
            traverseInOrder(temp->right);
        }
    }
};


int main() 
{
    LeafNode bst;
    bst.Insert(bst.getroot(),5);
    bst.Insert(bst.getroot(),10);
    bst.Insert(bst.getroot(),2);
    bst.Insert(bst.getroot(),1);
    bst.Insert(bst.getroot(),9);
    bst.Insert(bst.getroot(),8);
    bst.Insert(bst.getroot(),11);
    bst.Insert(bst.getroot(),15);
  
    bst.traverseInOrder(bst.getroot());
    cout << endl;
    bst.Middle(bst.getroot());
    
  
}

