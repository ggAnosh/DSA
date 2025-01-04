#include "postfix.h"
#include "prefix.h"

int main()
{

  char ch = 'B';

  char choice;

  while (ch != 'A')
  {

    cout << "Enter the choices you want to perform." << endl;

    cout << "A. Prefix on an expression." << endl;
    cout << "B. PostFix on an expression." << endl;

    cin >> choice;

    system("CLS");

    switch (choice)
    {

    case 'A':
    case 'a':
    {
      PreFix p1;
      p1.preFi();
      p1.displayResult();
      break;
    }

    case 'B':
    case 'b':
    {
      PostFix po;
      po.getData();
      po.Posfix();
      po.displaData();
      break;
    }

    default:
      cout << "Please choose a valid option." << endl;
      break;
    }

    cout << "Do you want to exit?" << endl;
    cout << "A. Yes" << endl;
    cout << "B. No" << endl;
    cin >> ch;
    system("CLS");
  }

  system("CLS");
  cout << "Exited from the program." << endl;

  return 0;
}