#include <iostream>
using namespace std;
class Node
{
public:
    int id;
    string name;
    int age;
    Node* leftChild;
    Node* rightChild;

    Node(int id, string name, int age)
        : id(id), name(name), age(age), leftChild(NULL), rightChild(NULL)
    {
    }
};

class StudentManagementSystem
{
private:
    Node* root;

public:
    StudentManagementSystem()
        : root(NULL)
    {
    }

    void AddStudent(int id, string name, int age)
    {
        Node* newStudent = new Node(id, name, age);
        if (root == NULL)
        {
            root = newStudent;

        }

        Node* current = root;
        while (true)
        {
            if (id < current->id)
            {
                if (current->leftChild == NULL)
                {
                    current->leftChild = newStudent;
                    return;
                }
                current = current->leftChild;
            }
            else
            {
                if (current->rightChild == NULL)
                {
                    current->rightChild = newStudent;
                    return;
                }
                current = current->rightChild;
            }
        }
    }

    Node* FindStudent(int id)
    {
        Node* current = root;
        while (current != NULL)
        {
            if (id == current->id)
            {
                return current;
            }
            if (id < current->id)
            {
                current = current->leftChild;
            }
            else
            {
                current = current->rightChild;
            }
        }
        return NULL;
    }

    void RemoveStudent(int id)
    {
        root = RemoveStudent(root, id);
        
    }

private:
    Node* RemoveStudent(Node* current, int id)
    {
        if (current == NULL)
        {
            return NULL;
        }

        if (id == current->id)
        {
            // Case 1: No children
            if (current->leftChild == NULL && current->rightChild == NULL)
            {
                delete current;
                return NULL;
            }

            // Case 2: Only one child
            if (current->rightChild == NULL)
            {
                Node* leftChild = current->leftChild;
                delete current;
                return leftChild;
            }
            if (current->leftChild == NULL)
            {
                Node* rightChild = current->rightChild;
                delete current;
                return rightChild;
            }

            // Case 3: Two children
            int smallestId = FindSmallestId(current->rightChild);
            current->id = smallestId;
            current->rightChild = RemoveStudent(current->rightChild, smallestId);
            return current;
        }

        if (id < current->id)
        {
            current->leftChild = RemoveStudent(current->leftChild, id);
            return current;
            
        }
        current = current->rightChild;
       
    }


    int FindSmallestId(Node* current)
    {
        while (current->leftChild != NULL)
        {
            current = current->leftChild;
        }
        return current->id;
    }

};

int main()
{
    StudentManagementSystem system;
    system.AddStudent(1, "Alice", 20);
    system.AddStudent(2, "Bob", 21);
    system.AddStudent(3, "Charlie", 22);

    Node* student = system.FindStudent(2);
    cout << "Found student: " << student->name << std::endl;

    system.RemoveStudent(2);
    student = system.FindStudent(2);
    if (student == NULL)
    {
        std::cout << "Student not found" << std::endl;
    }

    return 0;
}
