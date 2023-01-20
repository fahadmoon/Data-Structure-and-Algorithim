using StudentCsharpconsole;
using System;

namespace HelloWorld
{
    class Program
    {
        static void Main(string[] args)
        {
            Node head;
            Node n =new Node();
            head = n;
            head.insertFirst(head);
           
            head.Display(head);
        }
    }
}