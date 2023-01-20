#include <iostream>
using namespace std;

void pattern()
{
	int i=0;
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
    if(0==i++)
    {
    cout<<endl;
    cout << "$" << endl;
    cout<<endl;
	}
	int a=0;
	if(a>=0&&a<2)
	{
		 pattern();
		 a++;
	}	
	if(1==i)
    {
    cout<<endl;
    cout << "$" << endl;
    cout<<endl;
	}   
}
void P()
{
	
}
int main()
{ 
  pattern();
    
  return 0;
}

