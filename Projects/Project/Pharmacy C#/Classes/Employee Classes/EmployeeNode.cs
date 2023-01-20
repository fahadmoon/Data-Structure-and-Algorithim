using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1.Classes.Employee_Classes
{


    //Node Class for  the Employees
    internal class EmployeeNode
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
}
