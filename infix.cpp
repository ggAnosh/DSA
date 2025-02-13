#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

class Postfix
{

public:
  string expression, result = "";
  Stack<char> s;

  Postfix()
  {
    cout << "Enter the expression to work Postfix on." << endl;
    cin >> expression;
  }

  int comp(char c)
  {

    if (c == '$' || c == '^')
    {
      return 3;
    }
    else if (c == '*' || c == '/')
    {
      return 2;
    }
    else if (c == '+' || c == '-')
    {
      return 1;
    }
    return 0;
  }

  void operation()
  {
    char ch;
    for (int i = 0; i < expression.length(); ++i)
    {
      ch = expression[i];

      if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch == '(')
      {
        s.push(ch);
      }
      else if (ch == ')')
      {
        while (s.onTop() != '(')
        {
          result += s.pop();
        }
        s.pop();
      }
      else if (comp(ch) > s.onTop())
      {
        while (comp(ch) > s.onTop())
        {
          result += s.pop();
        }
      }
    }
  }

  void display()
  {
    cout << "The resultant expression is " << result << endl;
  }
};

int main()
{

  Postfix p1;
  p1.operation();
  p1.display();

  return 0;
}