#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int val)
  {
    data = val;
    next = nullptr;
  }
};
class Circular
{

public:
  Node *head;

  Circular()
  {
    head = nullptr;
  }

  void insertTop(int val)
  {
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
      head = newNode;
      head->next = head;
      return;
    }

    newNode->next = head;

    Node *last = head;
    while (last->next != head)
    {
      last = last->next;
    }
    last->next = newNode;
    head = newNode;
  }

  void insertEnd(int val)
  {

    Node *newNode = new Node(val);

    if (head == nullptr)
    {
      head = newNode;
      head->next = head;
      return;
    }

    Node *last = head;
    while (last->next != head)
    {
      last = last->next;
    }
    newNode->next = head;
    last->next = newNode;
  }

  void deleteTop()
  {
    if (head == nullptr)
    {
      cout << "Nothing to delete." << endl;
      return;
    }

    Node *current = head;

    while (current->next != head)
    {
      current = current->next;
    }

    current->next = head->next;
    head = current->next;
    delete current;
  }
};

int main()
{
  return 0;
}