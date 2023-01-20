// See https://aka.ms/new-console-template for more information
using System.Collections.Specialized;
using static System.Net.Mime.MediaTypeNames;
using System;


public class node
{
    public int data;
    public node next;
    public node()
    {        
        next = null;
    }
};

public class list {

    private node head;
    public list()
    {
        head = null;
    }

    public void nodeCreate(int val)
    {
        node temp = new node();
        temp.data = val;
        temp.next = null;
        head = temp;

        Console.WriteLine(temp.data);

    }

    static public void Main()
    {
        list list = new list();
        list.nodeCreate(5);
    }
};


    
      
    


