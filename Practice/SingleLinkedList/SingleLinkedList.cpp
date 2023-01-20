// SingleLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class node
{
public:
    string storyName;
    int priority;
    int teamNumber;
    int storyNumber;
    bool isDone;
    node* next;
    node(string story)
    {
        this->storyName = story;
        this->next = NULL;
    }
    //Destructor
    ~node()
    {

    }
};

class SingleLinkedList
{
private:
    node* head,*tail;
public:
    SingleLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    //isEmpty
    bool isEmpty()
    {
        if (head != NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //insertStoryAtLast
    void insertStoryAtLast(string n)
    {
        if(head!=NULL)
        {
            node* temp = new node(n);
            temp->storyName = n;
            temp->next = NULL;
            if (head == NULL)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                temp = tail;
            }
        }
        else
        {
            node* temp = new node(n);
            temp->storyName = n;
            tail->next = temp;
            temp = tail;

        }
        
    }
    //display
    void display()
    {
        node* curr;
        curr = head;
        while (curr != NULL)
        {
            cout << curr->storyName;
            curr=curr->next;
        }
        
    }
};

int main()
{
    SingleLinkedList s;
   s.insertStoryAtLast("zaibi");
   cout<< s.isEmpty();
    s.display();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
