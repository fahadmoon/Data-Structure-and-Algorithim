#include<iostream>    
using namespace std;

class InsertSort {
private:

    int i;
    int j;
    int temp;
public:
    int* a;
    int n;

    InsertSort()
    {
        cout << "Enter Index Number:";
        cin >> n;
        a = new int[n];


    }



    void Insert(int a[], int n)
    {

        cout << "Before sorting array elements are - \n";
        for (i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        for (i = 1; i < n; i++) {
            temp = a[i];
            j = i - 1;

            while ( temp <= a[j] && j >= 0 )
            {
                a[j + 1] = a[j];
                j = j - 1;
            }
            a[j + 1] = temp;
        }
    



        //Display Function
        cout << "\nAfter sorting array elements are - \n";
        for (i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

    }



};


int main()
{
    InsertSort  b;
    for (int i = 0; i < b.n; i++)
    {
        cout << "Enter Array Number: ";
        cin >> b.a[i];
    }
    //    int n = sizeof(b.a)/sizeof(b.a[0]);  

    b.Insert(b.a, b.n);

    return 0;
}