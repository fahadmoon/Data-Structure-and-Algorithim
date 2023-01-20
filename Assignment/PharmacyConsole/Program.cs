using System;
using System.Data;
using System.IO;
using System.Security.Cryptography;

public class AddEmployee
{
    public string nameEmployee { get; set; }
    public string phoneNo { get; set; }
    public int employeeid { get; set; }
    public string JoiningDate { get; set; }
    public int salary { get; set; }
    public string passwordEmloyee { get; set; }
    public string address { get; set; }
  /*  public AddEmployee EmployeeData { get; set; }
    public AddEmployee left { get; set; }
    public AddEmployee right { get; set; }
*/


    public AddEmployee(string nameEmployee, string phoneNo, int employeeid, string joiningDate, int salary, string passwordEmloyee, string address)
    {
        this.nameEmployee = nameEmployee;
        this.phoneNo = phoneNo;
        this.employeeid = employeeid;
        JoiningDate = joiningDate;
        this.salary = salary;
        this.passwordEmloyee = passwordEmloyee;
        this.address = address;
       /* left = null;
        right = null;*/

    }
}
public class EmployeeNode
{

    public AddEmployee EmployeeData { get; set; }
    public EmployeeNode left { get; set; }
    public EmployeeNode right { get; set; }

    public EmployeeNode(AddEmployee data)
    {
        EmployeeData = data;
        left = null;
        right = null;
    }

}
public class Employees
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
                    break;
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
                    
                    break;
                }
                current = current.right;
            }
        }
    }

    //Methed to perform an update because we should 1st search for employee id
    public AddEmployee SearchEmployee(int empolyID)
    {
        EmployeeNode curr = root;

      
        while (curr!=null)
        {
            if (curr.EmployeeData.employeeid == empolyID)
            {
                return curr.EmployeeData;

            }

            if (empolyID<curr.EmployeeData.employeeid)
            {
            
                curr =curr.left;
            }
            else if(empolyID > curr.EmployeeData.employeeid)
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


    static void Main(string[] args)
    {

        //  EmployeeNode employe = new EmployeeNode(data);

        Employees e=new Employees();
        e.InsertEmpolyee(new AddEmployee("Fahad", "09876", 1, "34", 34, "433", "Lahore"));

        e.InsertEmpolyee(new AddEmployee("ali", "09876", 2, "34", 34, "433", "Karachi"));
        e.InsertEmpolyee(new AddEmployee("ahmad", "09876", 5, "34", 34, "433", "Islamabad"));
        e.InsertEmpolyee(new AddEmployee("ahm", "09876", 4, "34", 34, "433", "Multan"));
        Console.WriteLine("Search:" );
        
       
        AddEmployee a= e.SearchEmployee(5);
        if (a==null)
        {
            Console.WriteLine("Name Not Found");
        }
        else
        {
            Console.WriteLine("Name: " + a.nameEmployee);
            Console.WriteLine("Address: " + a.address);
           
        }
       

        

        
        Console.WriteLine("Inorder traversal:");
        e.InorderTraversal();
        

    }
}