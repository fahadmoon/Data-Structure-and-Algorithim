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
        for(int i=1;i<n;i++)
        {
            int current=array[i];
            int j=i-1;

            while(array[j]>current && j>=0)
            {
                array[j]=array[j+1];
                j--;

            }
            array[i+1]=current;
        }

        //print Lo
        for(int i=0;i<n;i++)
        {
           cout<<array[i]<<" ";
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