#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node *next;
	Node()
	{
		data=0;
		next=NULL;
	}
};

class List{
	private: 
	Node* head;
	Node* tail;
	public: 
	List()
	{
		head=NULL;
		tail=NULL;
		
	}
	
	//InsertFirst()
	void InsertFirst(int value)
	{
		Node* temp;
		temp=new Node;
		temp->data=value;
		temp->next=head ;
		head=temp;
		
    }
    
    //InsertLast
    void InsertAtLast(int value)
    {
    	Node* temp=new Node();
    	
    	temp->data=value;
    	while()
	}
    void Display()
    {
    	Node *curr;
    	curr=head;
    	
        do
		{
    		cout<<curr->data<<" "<<endl;
    		curr=curr->next;
		}while(curr!=head);
	}
};
int main()
{
	List l;
	
	l.InsertFirst(4);
	l.Display();
	
}
