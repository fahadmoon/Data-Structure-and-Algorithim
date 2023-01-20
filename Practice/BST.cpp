#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

class BST
{
private:
	Node* root;
public:
	BST()
	{
		root = NULL;
	}
	Node* Getroot()
	{
		return root;
	}
	//Insert BST
	void Insert(Node* newNode,int val)
	{ 
		newNode = new Node(val);
		//newNode->data = val;
		if (root == NULL)
		{
			root = newNode;
			
		}

		Node* temp = root;
		while (true)
		{
			if (val < temp->data)
			{
				if(temp->left==NULL)
				{
					temp->left = newNode;
					
				}
				temp = temp->left;
			}
			//if (val > temp->data)
			else
			{
				if(temp->right==NULL)
				{
					temp->right = newNode;
					
				}
				temp = temp->right;
			}
		}
	}

	void Inorder(Node* temp)
	{
		if (temp != NULL)
		{
			Inorder(temp->left);
			cout << temp->data << " ";
			Inorder(temp->right);
		}
		
	}
};

int main()
{	
	BST b;
	b.Insert(b.Getroot(),3);
	b.Insert(b.Getroot(),2);
	b.Insert(b.Getroot(), 1);
	b.Insert(b.Getroot(), 5);
	b.Insert(b.Getroot(), 7);
	b.Inorder(b.Getroot());
}
