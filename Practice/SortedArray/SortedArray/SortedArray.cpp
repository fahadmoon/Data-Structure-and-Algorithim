// SortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//Class Sorted Array
class SortedArray
{
private:
    
public:
   
    int arr[5];
    void SortedArr(int arr[])
    {
        int a;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] < arr[j])
                {
                    
                     a=arr[i] ;
                    arr[i] =arr[j];
                    arr[j] = a;

                }
            }

        }

        for (int i = 0; i < 5; i++)
        {
            cout << arr[i] << " ";

        }
    }
};

int main()
{
    SortedArray sA;
    cout << "Enter Number" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> sA.arr[i];
     }
    sA.SortedArr(sA.arr);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
