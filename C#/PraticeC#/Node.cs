using System;
using System.Collections.Generic;
using System.Diagnostics.SymbolStore;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;

namespace PraticeC
{
    internal class Node
    {
        private object data;
        private Node next;

        //Constructor
        public Node(object data,Node next)
        {
           this.data =data;
           this.next = next;
        }
        public object Data
        {
            get { return this.data; }
            set { this.data = value; }
        }
        public Node Next
        {
            get { return this.next; } 
            set { this.next = value; }
        }
    }
}
