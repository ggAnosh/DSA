#include <iostream>
using namespace std;

class Queue
{

public:
  int rear, front, *q, size, s;

  Queue()
  {
    cout << "Enter the size of the Queue" << endl;
    cin >> size;

    q = new int[size];
    rear = -1;
    front = 0;
    s = 0;
  }

  bool isEmpty()
  {
    return s == 0 ? true : false;
  }

  bool isFull()
  {
    return rear == size - 1 ? true : false;
  }

  void enqueue()
  {

    if (!isFull())
    {
      ++rear;
      cout << "Enter the element to be enqueued." << endl;
      cin >> q[rear];
      ++s;
      cout << "Sucessfully enqueued." << endl;
    }
    else
    {
      cout << "Queue is already full." << endl;
    }
  }

  void dequeue()
  {

    if (!isEmpty())
    {
      cout << "Element Dequeued: " << q[front] << endl;
      ++front;
      --s;
    }
    else
    {
      cout << "Queue is empty." << endl;
    }
  }

  void traverse()
  {
    if (!isEmpty())
    {
      for (int i = front; i < rear; ++i)
      {
        cout << q[i] << " ";
      }
      cout << endl;
    }
    else
    {
      cout << "Queue is empty." << endl;
    }
  }
};

int main()
{

  return 0;
}