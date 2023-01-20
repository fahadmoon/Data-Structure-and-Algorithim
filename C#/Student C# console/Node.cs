using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StudentCsharpconsole
{
    internal class Node
    {
        Student data;
        public Node next;
        public Node()
        {
            next = null;
        }

        public void insertFirst(Node head)
        {
            Node newnode = new Node();
            if (head==null)
            {
                head = newnode;
            }
            newnode.next = head;
            head = newnode;
           
        }
        public void Display(Node head)
        {
            while(head!=null)
            {
                Console.WriteLine(head.data.name);
                Console.WriteLine(head.data.email);
                Console.WriteLine(head.data.age);
                head = head.next;
            }
        }
    }
}
