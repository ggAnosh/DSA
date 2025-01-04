#include <iostream>
#include <stack>
using namespace std;

class Prefix
{

public:
  string expression, preFix, rExpression, fPr;
  stack<char> ch;

  void getData()
  {
    cout << "Enter the expression to perform prefix operation on. " << endl;
    cin >> expression;
  }

  void revExpression()
  {
    for (int i = expression.length() - 1; i >= 0; --i)
    {
      rExpression += expression[i];
    }
  }

  int compOp(char w)
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

  void reF()
  {
    char c;

    for (int i = 0; i < rExpression.length(); ++i)
    {
      c = rExpression[i];

      if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
      {
        preFix += c;
      }
      else if (c == ')')
      {
        ch.push(')');
      }
      else if (c == '(')
      {
        while (ch.top() != ')')
        {
          if (ch.top() != ')')
            preFix += ch.top();
          ch.pop();
        }
        ch.pop();
      }
      else
      {
        while (!ch.empty() && compOp(ch.top()) >= compOp(c))
        {
          preFix += ch.top();
          ch.pop();
        }
        ch.push(c);
      }
    }

    while (!ch.empty())
    {
      preFix += ch.top();
      ch.pop();
    }
  }

  void reverseResult()
  {
    for (int i = preFix.length() - 1; i >= 0; --i)
    {
      fPr += preFix[i];
    }
  }

  void result()
  {
    cout << "Final result is " << fPr << endl;
  }
};

int main()
{

  Prefix p1;
  p1.getData();
  p1.revExpression();
  p1.reF();
  p1.reverseResult();
  p1.result();

  return 0;
}