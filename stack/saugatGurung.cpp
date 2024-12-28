#include <iostream>
using namespace std;

class Stack
{

public:
  int index, size, *stack;

  Stack()
  {

    cout << "Define the size of the stack." << endl;
    cin >> size;
    stack = new int[size];
    index = -1;
  }

  void emptyStack()
  {
    index = -1;
    cout << "The stack is now empty." << endl;
  }

  bool isEmpty()
  {
    return (index == -1) ? true : false;
  }

  bool isFull()
  {
    return (index == size - 1) ? true : false;
  }

  void push()
  {

    if (!isFull())
    {
      int val;
      ++index;
      cout << "Enter the value you want to add in the stack!!" << endl;
      cin >> val;
      stack[index] = val;
      cout << "Element successfully added into the stack." << endl;
      system("CLS");
    }
    else
    {
      cout << "The stack is full." << endl;
    }
  }

  void pop()
  {

    if (!isEmpty())
    {
      cout << "The data on top of stack now " << stack[index] << endl;
      --index;
    }
    else
    {
      cout << "The stack is empty." << endl;
    }
  }

  void traverse()
  {

    if (!isEmpty())
    {
      cout << "Displaying elements from the top of the stack: " << endl;
      for (int i = index; i >= 0; ++i)
      {

        cout << stack[i] << " ";
      }
    }
    else
    {
      cout << "The stack is empty." << endl;
    }
  }
};

int main()
{

  Stack s1;

  char ch = 'A';

  char choice;

  while (ch == 'A')
  {

    cout << "Enter your choice:" << endl;
    cout << "A. Enter any element in the stack." << endl;
    cout << "B. Display element from the stack." << endl;
    cout << "C. Find if stack is empty." << endl;
    cout << "D. Find if stack is full." << endl;
    cout << "E. Traverse each element of the stack." << endl;

    cin >> choice;

    switch (choice)
    {
    case 'A':
      s1.push();
      break;

    case 'B':
      s1.pop();
      break;

    case 'C':
      if (s1.isEmpty())
      {
        cout << "The stack is empty." << endl;
      }
      else
      {
        cout << "The stack is not empty." << endl;
      }
      break;

    case 'D':
      if (s1.isFull())
      {
        cout << "The stack is full." << endl;
      }
      else
      {
        cout << "The stack is not full." << endl;
      }
      break;

    case 'E':
      s1.traverse();
      break;
    }

    cout << "Do you want to continue?" << endl;
    cout << "A. Yes" << endl;
    cout << "B. No" << endl;
    cin >> ch;
  }

  return 0;
}