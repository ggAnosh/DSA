#include <iostream>
using namespace std;

class Priority
{

public:
  int rear, front, size, *q;

  Priority()
  {
    cout << "Enter the size of the queue." << endl;
    cin >> size;
    q = new int[size];
    rear = 0;
    front = 0;
  }

  bool isEmpty()
  {
    return (rear == front);
  }

  bool isFull()
  {
    return (rear == size - 1);
  }

  void enqueue()
  {
    if (!isFull())
    {

      cout << "Enter the element to be enqueued." << endl;
      if (rear == 0)
      {
        cin >> q[rear];
        ++rear;
      }
      else
      {
        cin >> q[rear];
        ++rear;
        for (int i = front; i < rear; ++i)
        {
          for (int j = i + 1; j <= rear; ++j)
          {
            if (q[i] > q[j])
            {
              int temp = q[i];
              q[i] = q[j];
              q[j] = temp;
            }
          }
        }
      }
    }
  }

  void dequeue()
  {

    if (!isEmpty())
    {
      cout << "Element dequeued: " << q[front] << endl;
      ++front;
    }
  }
};

int main()
{
  return 0;
}