#include "stack.h"
class PostFix
{
public:
  string expression, postFix;
  Stack<char> s1;

  void getData()
  {
    cout << "Enter the expression to work the postFix on." << endl;
    cin >> expression;
  }

  int opComp(char w)
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

  void Posfix()
  {

    for (int i = 0; i < expression.length(); ++i)
    {

      char word = expression[i];

      if (word >= 'a' && word <= 'z' || word >= 'A' && word <= 'Z')
      {
        postFix += word;
      }
      else if (word == '(')
      {
        s1.push(word);
      }
      else if (word == ')')
      {
        while (s1.onTop() != '(')
        {
          postFix += s1.onTop();
          s1.pop();
        }
        s1.pop();
      }
      else if (!s1.isEmpty() && opComp(word) < opComp(s1.onTop()))
      {
        while (opComp(word) < opComp(s1.onTop()))
        {
          postFix += s1.onTop();
          s1.pop();
        }
      }
      else
      {
        s1.push(word);
      }
    }
  }

  void displaData()
  {
    while (!s1.isEmpty())
    {
      postFix += s1.onTop();
      s1.pop();
    }

    cout << "The result is " <<  postFix << endl;
  }
};