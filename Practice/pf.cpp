//#include <iostream>
//#include <cctype>
//using namespace std;
////Problem1
//void Problem1(char ch)
//{
//    if (isdigit(ch))
//    {
//        if (ch % 2 == 0)
//        {
//            cout << "It is an even number." << endl;
//        }
//        else
//        {
//            cout << "It is an odd number." << endl;
//        }
//    }
//    else if (isalpha(ch)) 
//	{
//        if (isupper(ch))
//        {
//            cout << "It is an upper case alphabet." << endl;
//        }
//        else {
//            cout << "It is a lower case alphabet." << endl;
//        }
//        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
//        {
//            cout << "It is a vowel." << endl;
//        }
//        else
//        {
//            cout << "It is a consonant." << endl;
//        }
//    }
//    else
//    {
//        cout << "It is a special character." << endl;
//    }
//
//}
////Problem 2
//void Problem2(int num)
//{
//    if (num / 10000 == num % 10 && (num / 1000) % 10 == (num / 10) % 10 && (num / 100) % 10 == (num / 1000) % 10)
//    {
//        cout << "It is the same from both sides." << endl;
//    }
//    else
//    {
//        cout << "It is not the same from both sides." << endl;
//    }
//}
//
//
////Problem3
//void Problem3()
//{
//    int roll1, roll2, roll3;
//    cout << "Enter the first dice roll: ";
//    cin >> roll1;
//    cout << "Enter the second dice roll: ";
//    cin >> roll2;
//    cout << "Enter the third dice roll: ";
//    cin >> roll3;
//
//    if ((roll1 == 5 || roll1 == 6) && (roll2 == 3 || roll2 == 4) && (roll3 == 1 || roll3 == 2)) {
//        cout << "You won!" << endl;
//    }
//    else {
//        cout << "You lost." << endl;
//    }
//}
//
//int main() {
//    char a;
//   
//do{
//	 cout << "1. Problem 1" << endl;
//    cout << "2. Problem 2" << endl;
//    cout << "3. Problem 3" << endl;
//    cin >> a;
//    switch (a)
//    {
//    case '1':
//        char ch;
//        cout << "Enter a character: ";
//        cin >> ch;
//        Problem1(ch);
//        break;
//
//    case '2':
//        int num;
//        cout << "Enter a 5-digit number: ";
//        cin >> num;
//        Problem2(num);
//        break;
//    case '3':
//        Problem3();
//        break;
//        default:
//        	cout<<"Correct Press..."<<endl;
//
//    }
//	}while(true);
//    return 0;
//}






//#include <iostream>
//using namespace std;
//
//int main() {
//  int start, end;
//  cout << "Enter the starting point: ";
//  cin >> start;
//  cout << "Enter the ending point: ";
//  cin >> end;
//  
//  for (int i = start; i >= end; i--) {
//    cout << i << " ";
//  }
//  cout << endl;
//
//  return 0;
//}
#include <iostream>
using namespace std;

int main()
{ 
  for (int i = 0; i < 3; i++) 
  {
    for (int j = 0; j < 10; j++)
	{
      if (j % 2 == 0) 
	  {
        cout << "*";
      } 
	  else 
	  {
        cout << "-";
      }
    }
    cout<<endl;
    if(0==i)
    {
    cout<<endl;
    cout << "$" << endl;
    cout<<endl;
	}
	if(1==i)
    {
    cout<<endl;
    cout << "$" << endl;
    cout<<endl;
	}
    
  }
  return 0;
}


