using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StudentBinaryTreeSearchTree
{
    internal class StudentBinaryTree
    {
        public StudentNode root;

        public StudentBinaryTree()
        {
            root = null;
        }

        // Insert a new node into the tree
        public void Insert(StudentData data)
        {
            StudentNode newNode = new StudentNode(data);

            if (root == null)
            {
                root = newNode;
            }
            else
            {
                StudentNode current = root;
                StudentNode parent;
                while (true)
                {
                    parent = current;
                    if (data.ID < current.data.ID)
                    {
                        current = current.leftChild;
                        if (current == null)
                        {
                            parent.leftChild = newNode;
                            break;
                        }
                    }
                    else
                    {
                        current = current.rightChild;
                        if (current == null)
                        {
                            parent.rightChild = newNode;
                            break;
                        }
                    }
                }
            }
        }

        // Search for a node with a specific ID
        public StudentNode Search(int ID)
        {
            StudentNode current = root;
            while (current != null)
            {
                if (current.data.ID == ID)
                {
                    return current;
                }
                else if (ID < current.data.ID)
                {
                    current = current.leftChild;
                }
                else
                {
                    current = current.rightChild;
                }
            }
            return null;
        }
    }
}
