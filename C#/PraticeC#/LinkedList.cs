using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PraticeC
{
    internal class LinkedList
    {
        private Node head;
        private int size;

       public LinkedList()
        {
            this.head = null;
            this.size = 0;
        }
        public bool IsEmpty
        {
            get{ return this.size == 0; }
        }
        public int Count
        {
            get { return this.size; }   
        }

    }
}
