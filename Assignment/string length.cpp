#include <iostream>
using namespace std;
const int size = 5;

class Queue {
private:
  int arr[size];
  int front;
  int rear;

public:
  Queue() {
    front = 0;
    rear = -1;
  }

  void enqueue(int value) {
    if (rear == size - 1) {
      cout << "Queue is full" <<endl;
      return;
    }
    else
    {
    	arr[++rear] = value;
	}
    
  }

  void dequeue() {
    if (front > rear) 
	{
      cout << "Queue is empty" << endl;
      return;
    }
    else
    {
    	++front;
	}
    
  }

  int get_front() 
  {
    if (front > rear) 
	{
      cout << "Queue is empty" << endl;
      return -1;
    }
    return arr[front];
  }

  bool is_empty() 
  {
  	return front > rear;
  }
};

int main() {
  Queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);

while (!q.is_empty()) 
{
    cout << q.get_front() <<endl;
    q.dequeue();
    
  }

  return 0;
}

