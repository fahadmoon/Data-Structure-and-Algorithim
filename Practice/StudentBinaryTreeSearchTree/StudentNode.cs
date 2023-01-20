using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StudentBinaryTreeSearchTree
{
    internal class StudentNode
    {
        public StudentData data;
        public StudentNode leftChild;
        public StudentNode rightChild;

        public StudentNode(StudentData data)
        {
            this.data = data;
            leftChild = null;
            rightChild = null;
        }
    }
}
