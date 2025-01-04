#include <iostream>
using namespace std;

int stack[100], n = 100, top = -1;

bool isempty()
{
  return (top <= -1) ? true : false;
}

bool isFull()
{
  return (top >= n) ? true : false;
}

void push(int val)
{
  if (top >= n - 1)
  {
    cout << "Stack overflow" << endl;
  }
  else
  {
    top++;
    stack[top] = val;
  }
}

void pop()
{
  if (isempty())
  {
    cout << "Stack Underflow" << endl;
  }
  else
  {
    cout << "The popped element is: " << stack[top] << endl;
    top--;
  }
}
void traverse()
{
  if (isempty())
  {
    cout << "The stack is empty." << endl;
  }
  else
  {
    cout << "Stack elements are:" << endl;
    for (int i = top; i >= 0; --i)
    {
      cout << stack[i] << " ";
    }
    cout << endl;
  }
}

int topElements()
{
  if (isempty())
  {
    cout << "The stack is empty." << endl;
    return -1;
  }
  else
  {
    return stack[top];
  }
}

int main()
{
  int ch, val;
  cout << "1. Make empty." << endl;
  cout << "2. Push." << endl;
  cout << "3. Pop." << endl;
  cout << "4. Traverse." << endl;
  cout << "5. topElement." << endl;
  cout << "6. Exit." << endl;

  do
  {
    cout << "Enter the choice:" << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
      cout << "The stack is empty." << endl;
      break;
    case 2:
      cout << "Enter value to be pushed:" << endl;
      cin >> val;
      push(val);
      break;
    case 3:
      pop();
      break;
    case 4:
      traverse();
      break;

    case 5:
      val = topElements();
      if (val != -1)
      {
        cout << "Top element:" << val << endl;
      }
      break;

    case 6:
      cout << "Exiting...." << endl;
      break;

    default:
      cout << "Inavlid choice." << endl;
    }
  } while (ch != 4);
  return 0;
}