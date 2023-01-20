#include <iostream>
using namespace std;
class Node {
public:
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

class LeafNode
{
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
	void leafNode(Node* temp)
	{
        if (temp != NULL)
        {
            leafNode(temp->left);
            leafNode(temp->right);
            if (temp->left == NULL && temp->right == NULL)
            {
                cout << temp->value << " ";
            }
            /*else if ()
            {
                cout << temp->value << " ";

            }*/
          
        }
			
	}

};
int main()
{
	LeafNode l;
	l.Insert(l.getroot(), 5);
	l.Insert(l.getroot(), 2);
	l.Insert(l.getroot(), 3);
	l.Insert(l.getroot(), 7);
	l.Insert(l.getroot(), 6);

   
	l.traverseInOrder(l.getroot());
    cout << endl;
	l.leafNode(l.getroot());
}