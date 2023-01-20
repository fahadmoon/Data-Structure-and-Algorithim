using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StudentCsharpconsole
{
    internal class Student
    {
        public string name;
        public string email;
        public int age;
        public Student()
        {
            Console.WriteLine("Enter Name: ");
            name = Console.ReadLine();
            Console.WriteLine("Enter Email: ");
            email = Console.ReadLine();
            Console.WriteLine("Enter Age: ");
            age =Convert.ToInt32( Console.ReadLine());



        }
    }
}
