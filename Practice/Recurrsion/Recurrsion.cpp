
#include <iostream>
using namespace std;
void count(int val)
{
	cout << val;
	if (val < 2)
	{
		count(val + 1);
	}
	cout << val;
}
int main()
{
	count(0);
}
