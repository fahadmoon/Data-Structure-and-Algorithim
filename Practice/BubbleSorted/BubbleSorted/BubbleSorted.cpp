// BubbleSorted.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class BubbleSort
{
private:
    int n;
public:
    int *array;
    BubbleSort()
    {
        cout << "Enter Index:" << endl;
        cin >> n;
        array = new int[n];
    }
    int Get_n()
    {
        return n;
    }
    void Bubble(int array[])
    {
        
        // for (int i = 0; i < n; i++)
        // {
        //     for(int j=0;j<i;j++)
        //     if (array[i] < array[j])
        //     {
        //         int temp=array[i];

        //         array[i] = array[j];
        //         array[j] = temp;
        //     }
        // }

int c=1;
while (c<n)
{
      for (int i = 0; i < n-c; i++)
        {
            
            
            if (array[i] > array[i+1])
            {
                int temp=array[i];

                array[i] = array[i+1];
                array[i+1] = temp;
            }
            
        }
        c++;
}

       
        
        //Print
        for (int i = 0; i < n; i++)
        {
            cout << array[i] << " ";
        }

    }

};

int main()
{
    BubbleSort b;
    int n = b.Get_n();
    for (int i = 0; i < n; i++)
    {
        cin >> b.array[i];
    }
    b.Bubble(b.array);
}