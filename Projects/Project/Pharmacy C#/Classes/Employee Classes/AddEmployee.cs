using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1.Classes.Employee_Classes
{
    internal class AddEmployee
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
}
