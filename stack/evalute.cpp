#include <iostream>
#include <stack>
using namespace std;

class Evaluate
{

  string expression, result;
  stack<char> ch;

  void getData()
  {
    cout << "Enter the expresion on which to perform the evaluate expression on: " << endl;
    cin >> expression;
  }

  void expres(char c)
  {

    switch (c)
    {

      int r;

    case '+':
      r = ch.top() + ch.top() - 1;
      ch.pop();
      ch.pop();
      ch.push(r);
      break;
    }
  }

  void eva()
  {

    for (int i = 0; i < expression.length(); ++i)
    {
      char c = expression[i];

      if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
      {
        ch.push(c);
      }
    }
  }
};

int main()
{

  return 0;
}
