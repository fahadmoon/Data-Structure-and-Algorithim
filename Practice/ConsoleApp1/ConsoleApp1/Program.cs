using System;
using System.Diagnostics.CodeAnalysis;

namespace VariablesExampleOne
{
    class Program
    {
        static void Main()
        {
           int num1 = Convert.ToInt16(Console.ReadLine());
            Divide(num1);
        }
        public static float Divide(int num1)
        {
            int sum = 0;
            // Replace the below code line with your code
           
           for(int i=1;i<=num1;i++)
            {
                if(i%2==0)
                  sum += i;
                
            }
            Console.WriteLine(sum);




            return 0;
        }

        /*  static void Main(string[] args)
          {
              *//*int x = 2;
              int y = 5;
              int z = 8;
              Console.WriteLine(x > z ? 5 : 3 < y ? 10 : 15);*/

        /* int[,] arr = new int[3, 3] { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
         Console.Out.WriteLine(arr[2, 1]);*//*


     }*/
    }
}