#include <iostream>
#include <stack>
#include <string>
using namespace std;

class PostFix
{

public:
  string postFix, expression;
  stack<char> ch;

  void getData()
  {
    cout << "Enter the expression on which to perform the post fix operation on. " << endl;
    cin >> expression;
  }

  int opCom(char w)
  {

    if (w == '+' || w == '-')
    {
      return 1;
    }
    else if (w == '*' || w == '/')
    {
      return 2;
    }
    else if (w == '$')
    {
      return 3;
    }
    return 0;
  }

  void con()
  {

    for (int i = 0; i < expression.length(); ++i)
    {
      char c = expression[i];

      if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
      {
        postFix += c;
      }
      else if (c == '(')
      {
        ch.push('(');
      }
      else if (c == ')')
      {
        while (ch.top() != '(')
        {
          if (ch.top() != '(')
          {
            postFix += ch.top();
            ch.pop();
          }
          ch.pop();
        }
      }
      else
      {
        while (opCom(ch.top()) >= opCom(c))
        {
          postFix += ch.top();
          ch.pop();
        }
        ch.push(c);
      }
    }
    while (!ch.empty())
    {
      postFix += ch.top();
      ch.pop();
    }
  }

  void displayData()
  {
    cout << postFix << endl;
  }
};

int main()
{
  PostFix p1;
  p1.getData();
  p1.con();
  p1.displayData();

  return 0;
}