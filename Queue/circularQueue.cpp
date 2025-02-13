#include <iostream>
using namespace std;

class Circular
{

public:
  int size, front, rear, *q;

  Circular()
  {
    cout << "Enter the max size of the queue." << endl;
    cin >> size;
    q = new int[size];
    front = -1;
    rear = -1;
  }

  bool isEmpty()
  {
    return front == -1 ? true : false;
  }

  bool isFull()
  {
    return (rear + 1) % size == front ? true : false;
  }

  void enqueue()
  {
    if (!isFull())
    {
      cout << "Insert the element to be enqeued. " << endl;
      rear = (rear + 1) % size;
      front == 0 ? ++front : front = front;
      cin >> q[rear];
      cout << "Enqueued" << endl;
    }
  }

  void dequeue()
  {
    if (!isEmpty())
    {
      cout << "The element dequeued: " << endl;
      cout << q[front];

      if (front == rear)
      {
        front = rear = -1;
      }
      else
      {

        front = (front + 1) % size;
      }
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
      int i = front;
      while (i != rear)
      {
        cout << q[i] << " ";
        i = (i + 1) % size;
      }
      cout << q[rear] << endl;
    }
  }
};