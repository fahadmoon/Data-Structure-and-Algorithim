using System;
using System.Collections.Generic;

// Student class
class Student
{
    public string Name { get; set; }
    public int Age { get; set; }
    public string Gender { get; set; }
}

// Node class for the BST
class Node
{
    public Student Data { get; set; }
    public Node Left { get; set; }
    public Node Right { get; set; }

    public Node(Student data)
    {
        Data = data;
        Left = null;
        Right = null;
    }
}

// BST class
class BST
{
    public Node Root { get; set; }

    public BST()
    {
        Root = null;
    }

    // Method to insert a new student into the BST
    public void Insert(Student data)
    {
        // Create a new node for the student
        Node newNode = new Node(data);

        // If the tree is empty, set the root to the new node
        if (Root == null)
        {
            Root = newNode;
            return;
        }

        // Start at the root
        Node current = Root;

        // Use a loop to find the correct position for the new node
        while (true)
        {
            // If the new node should go to the left of the current node
            if (data.Name.CompareTo(current.Data.Name) < 0)
            {
                // If there is no left child, add the new node here
                if (current.Left == null)
                {
                    current.Left = newNode;
                    break;
                }
                // Otherwise, move to the left child and continue searching
                else
                {
                    current = current.Left;
                }
            }
            // If the new node should go to the right of the current node
            else
            {
                // If there is no right child, add the new node here
                if (current.Right == null)
                {
                    current.Right = newNode;
                    break;
                }
                // Otherwise, move to the right child and continue searching
                else
                {
                    current = current.Right;
                }
            }
        }
    }

    // Method to search for a student in the BST
    public Student Search(string name)
    {
        // Start at the root
        Node current = Root;

        // Use a loop to search for the student
        while (current != null)
        {
            // If the current node contains the student, return it
            if (current.Data.Name == name)
            {
                return current.Data;
            }
            // If the student's name is less than the current node's name, move to the left child
            else if (name.CompareTo(current.Data.Name) < 0)
            {
                current = current.Left;
            }
            // Otherwise, move to the right child
            else
            {
                current = current.Right;
            }
        }

        // If the student was not found, return null
        return null;
    }
    public void Delete(string name)
    {
        // Start at the root
        Node current = Root;
        Node parent = null;

        // Use a loop to search for the student
        while (current != null)
        {
            // If the current node contains the student, delete it
            if (current.Data.Name == name)
            {
                // Case 1: The current node has no children
                if (current.Left == null && current.Right == null)
                {
                    // If the current node is the root, set the root to null
                    if (current == Root)
                    {
                        Root = null;
                    }
                    // Otherwise, set the parent's child to null
                    else
                    {
                        if (parent.Left == current)
                        {
                            parent.Left = null;
                        }
                        else
                        {
                            parent.Right = null;
                        }
                    }
                }
                // Case 2: The current node has no left child
                else if (current.Left == null)
                {
                    // If the current node is the root, set the root to the right child
                    if (current == Root)
                    {
                        Root = current.Right;
                    }
                    // Otherwise, set the parent's child to the right child
                    else
                    {
                        if (parent.Left == current)
                        {
                            parent.Left = current.Right;
                        }
                        else
                        {
                            parent.Right = current.Right;
                        }
                    }
                }
                // Case 3: The current node has no right child
                else if (current.Right == null)
                {
                    // If the current node is the root, set the root to the left child
                    if (current == Root)
                    {
                        Root = current.Left;
                    }
                    // Otherwise, set the parent's child to the left child
                    else
                    {
                        if (parent.Left == current)
                        {
                            parent.Left = current.Left;
                        }
                        else
                        {
                            parent.Right = current.Left;
                        }
                    }
                }
                // Case 4: The current node has two children
                else
                {
                    // Find the inorder successor of the current node (the leftmost child of the right subtree)
                    Node successor = current.Right;
                    Node successorParent = current;
                    while (successor.Left != null)
                    {
                        successorParent = successor;
                        successor = successor.Left;
                    }

                    // Replace the current node's data with the successor's data
                    current.Data = successor.Data;

                    // If the successor has a right child, set the parent's left child to the right child
                    if (successor.Right != null)
                    {
                        if (successorParent.Left == successor)
                        {
                            successorParent.Left = successor.Right;
                        }
                        else
                        {
                            successorParent.Right = successor.Right;
                        }
                    }
                    // Otherwise, set the parent's left child to null
                    else
                    {
                    }
                }

            }
        }
    }
}