#include<iostream> //haeder files
using namespace std;

// create node
struct Node { 
    int data; 
     Node *next; 
}; 

// this function for insert the new node in linked list 
void sortedInsert(int arr[]){ 
Node* new_node=new Node;
    Node* head;
    Node* temp = head; 
    
    // Case 1 when list is empty
    if (temp == NULL){ 
        new_node->next = new_node; 
        head = new_node; 
    } 

   
    else if (temp->data >= new_node->data){ 

        while( temp->next != head) 
            temp = temp->next; 
        temp->next = new_node; 
        new_node->next = head; 
        head = new_node; 
    } 
    else{ 
        
        while ( temp->next!= head && temp->next->data < new_node->data) 
            temp = temp->next; 
 
        new_node->next =temp->next; 
        temp->next = new_node; 
    } 
} 

//Display
void printList() { 
    Node *start;
    Node *temp; 

    if(start != NULL){ 
        temp = start; 
        cout<<"\n"; 
        do { 
            cout<<temp->data<<" "; 
            temp = temp->next; 
        } while(temp != start); 
    } 
} 

// main method start
int main(){
    
    int arr[] = {12, 56, 2, 11, 1, 90}; 
    int list_size, i; 

    for (i = 0; i< 6; i++) { 
       
        sortedInsert(arr[i]); 
    } 

    printList(start); 

    return 0; 
} 
