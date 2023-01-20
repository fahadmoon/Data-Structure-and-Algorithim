using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1.Classes.Employee_Classes
{
    internal class Employees
    {
        public EmployeeNode root { get; set; }

        public Employees()
        {
            root = null;
        }

        // insert a new Employee into the Employees
        public void InsertEmpolyee(AddEmployee data)
        {
            //create a new node for store the data
            EmployeeNode newNode = new EmployeeNode(data);


            //If the tree is empty, connect the root
            if (root == null)
            {
                root = newNode;
                return;
            }


            ////Start the root 
            EmployeeNode current = root;


            ///use the lopp find the correct position for the new node

            while (true)
            {
                //if the new node should go to left side of the parent......

                if (data.employeeid < current.EmployeeData.employeeid)
                {
                    //check the right side current if not equal to null current go to next
                    if (current.left == null)
                    {
                        current.left = newNode;

                        return;
                    }
                    current = current.left;

                }


                ///if the new node  should go to right the right side of the parent
                ///
                if (data.employeeid > current.EmployeeData.employeeid)
                {
                    //check the right side current if not equal to null current go to next
                    if (current.right == null)
                    {
                        current.right = newNode;
                        return;
                    }
                    current = current.right;
                }
            }
        }

        //Search 
        public AddEmployee SearchEmployee(int empolyID)
        {
            EmployeeNode curr = root;


            while (curr != null)
            {
                if (curr.EmployeeData.employeeid == empolyID)
                {
                    return curr.EmployeeData;

                }

                if (empolyID < curr.EmployeeData.employeeid)
                {

                    curr = curr.left;
                }
                else if (empolyID > curr.EmployeeData.employeeid)
                {

                    curr = curr.right;
                }
            }

            return null;
        }
        // Method to perform an inorder traversal of the BST
        public void InorderTraversal()
        {
            // Use an inorder traversal to print the students in ascending order
            InorderTraversal(root);
        }

        public void InorderTraversal(EmployeeNode current)
        {
            // Recursively traverse the left subtree
            if (current != null)
            {
                InorderTraversal(current.left);


                // Print the data of the current node
                Console.WriteLine(current.EmployeeData.employeeid);
                Console.WriteLine(current.EmployeeData.nameEmployee);

                // Recursively traverse the right subtree

                InorderTraversal(current.right);
            }
        }


    }
}
