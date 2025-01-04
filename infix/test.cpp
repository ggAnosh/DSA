#include <iostream>
using namespace std;

int main()
{

  string expression = "12";

  int num = static_cast<int>(expression[0]);
  cout << num;

  return 0;
}