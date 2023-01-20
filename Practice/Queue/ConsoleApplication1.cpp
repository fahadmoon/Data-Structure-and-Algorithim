#include<iostream>
using namespace std;

//const int size = 4;
class Queue 
{
private:
	int rear;
	int front;
	int size;
	int* arr;
public:
	//Constructor
	Queue()
	{
		size = 5;
		front = -1;
		rear = -1;
		arr = new int[size];
	}
	//Enqeue
	void EnQueue(int value)
	{
		if (rear == (front - 1) % (size - 1))
		{
			cout << "Queue is full" << endl;
		}
		else if (front == -1) 
		{
			front = 0;
			rear = 0;
			arr[rear] = value;
		}

		else if (rear == size - 1)
		{
			rear = 0;
			arr[rear] = value;
		}

		else
		{
			rear++;
			arr[rear] = value;
		}
	}

	//DeQueue
	void DeQueue()
	{
		if (front == -1)
		{
		   cout<<"Queue is Empty"<<endl;
		}

		int data = arr[front];
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else if (front == size - 1)
			front = 0;
		else
			front++;

		cout <<data << endl;
	}

	//Dispaly Function
     void Display()
	{
		if (front == -1)
		{
			cout << "Queue is Empty" << endl;
			
		}
		if (rear >= front)
		{
			for (int i = front; i <= rear; i++)
			{
				cout << arr[i] << endl;
			}
		}
		else
		{
			for (int i = front; i < size; i++)
			{
				cout << arr[i] << endl;
			}


			for (int i = 0; i <= rear; i++)
			{
				cout << arr[i] << endl;
			}
		}
	}



};

int main()
{
	Queue q;
	/*q.EnQueue(1);
	q.EnQueue(2);
	q.EnQueue(3);
	
	q.Display();
	
	q.DeQueue();
	q.DeQueue();
	cout << endl;
	q.Display();*/
	char c;
	while (true)
	{


		cout << "1. EnQueue" << endl;
		cout << "2. DeQueue" << endl;
		cout << "3. Display" << endl;
		cin >> c;
		switch (c)
		{
		case '1':
			int val;
			cout << "Enter Value" << endl;
			cin >> val;
			q.EnQueue(val);
			break;
		case '2':
			cout << endl;
			cout << "Delete " << endl;
			q.DeQueue();
			break;

		case '3':
			cout << endl;
			q.Display();
			break;
		default:
			break;
		}
	}
	return 0;
}
