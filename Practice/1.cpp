#include <iostream>
#include <cstdlib>

using namespace std;

// Node structure for a single element in the circular linked list
struct Node {
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Helper function to merge two sorted circular linked lists
// Returns a pointer to the head of the merged list
Node* merge(Node* a, Node* b) {
    // If either of the lists is empty, return the other one
    if (a == NULL) 
	    return b;
    if (b == NULL) 
	    return a;

    Node* result = NULL;

    // If a's data is smaller than b's, make a the head of the result list
    if (a->data <= b->data) {
        result = a;
        a = a->next;
    } else {
        result = b;
        b = b->next;
    }

    // Create a pointer to the last element in the result list
    Node* last = result;

    // Keep merging the two lists until one of them becomes empty
    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            last->next = a;
            last = last->next;
            a = a->next;
        } else {
            last->next = b;
            last = last->next;
            b = b->next;
        }
    }

    // Append the remaining elements from the non-empty list to the result list
    if (a != NULL) {
        last->next = a;
    } else {
        last->next = b;
    }

    // Return the head of the result list
    return result;
}

// Function to sort a circular linked list using merge sort
void mergeSort(Node*& head) {
    // Base case: if the list is empty or has only one element, return
    if (head == NULL || head->next == head) return;

    // Use the slow-fast pointer method to find the middle element of the list
    Node* slow = head;
    Node* fast = head;

    // Move the fast pointer twice as fast as the slow pointer
    // When the fast pointer reaches the end of the list, the slow pointer will be at the middle
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list into two halves at the middle
    Node* first = head;
    Node* second = slow->next;
    slow->next = head; // Make the two halves circular

    // Recursively sort the two halves
    mergeSort(first);
    mergeSort(second);

    // Merge the two sorted lists
    head = merge(first, second);
}

// Function to print the elements of a circular linked list
void printList(Node* head) {
    if (head == NULL) 
	     return;

    Node* current = head;
    do {
        cout << current->data << " ";
        current=current->next;
    }while(current!=head);
}
int main()
{
    
}

