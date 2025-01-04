#include "stack.h"
class PreFix
{

public:
  string expression, preFix, result;
  Stack<char> s1;

  PreFix()
  {

    cout << "Enter the expression to work the prefix principle on." << endl;
    cin >> expression;

    reverseString(expression, preFix);
  }

  void reverseString(string &ex, string &e)
  {
    for (int i = ex.length() - 1; i >= 0; --i)
    {
      e += ex[i];
    }
  }

  int opPrec(char w)
  {

    if (w == '+' || w == '-')
    {
      return 1;
    }
    else if (w == '*' || w == '/')
    {
      return 2;
    }
    else if (w == '$' || w == '^')
    {
      return 3;
    }
    return 0;
  }

  void preFi()
  {

    for (int i = 0; i < preFix.length(); ++i)
    {

      char w = preFix[i];

      if (w >= 'a' && w <= 'z' || w >= 'A' && w <= 'Z')
      {
        result += w;
      }
      else if (w == '(')
      {
        s1.push(w);
      }
      else if (w == ')')
      {
        while (s1.onTop() != '(')
        {
          result += s1.onTop();
          s1.pop();
        }
        s1.pop();
      }
      else
      {
        while (!s1.isEmpty() && opPrec(s1.onTop()) > opPrec(w))
        {
          result += s1.onTop();
          s1.pop();
        }
        s1.push(w);
      }
    }
  }

  void displayResult()
  {

    preFix = "";

    while (!s1.isEmpty())
    {
      result += s1.onTop();
      s1.pop();
    }

    reverseString(result, preFix);

    cout << "The result is " << preFix << endl;
    }
};