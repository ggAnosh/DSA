#include <iostream>
using namespace std;

class Node
{

public:
  int data;
  Node *next;
  Node *prev;

  Node(int val)
  {
    data = val;
    next = nullptr;
    prev = nullptr;
  }
};

class Doubly
{

public:
  Node *head;

  Doubly()
  {
    head = nullptr;
  }

  void insertTop(int val)
  {

    Node *newNode = new Node(val);

    if (head == nullptr)
    {
      head = newNode;
      head->next = newNode;
      return;
    }

    newNode->next = head;
    head->prev = newNode;

    Node *last = head;
    while (last->next != head)
    {
      last = last->next;
    }
    head = newNode;
    last->next = head;
  }

  void insertEnd(int val)
  {
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
      head = newNode;
      head->next = newNode;
      return;
    }

    Node *last = head;

    while (last->next != head)
    {
      last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
    newNode->next = head;
    head->prev = newNode;
  }

  void deleteTop()
  {

    if (head == nullptr)
    {
      cout << "Nothing to delete." << endl;
      return;
    }
    else if (head->next == head)
    {
      delete head;
      head = nullptr;
      return;
    }

    Node *last = head;
    while (last->next != head)
    {
      last = last->next;
    }

    last->next = head->next;
    head->next->prev = last;
    delete head;
    head = last->next;
  }

  void deleteEnd()
  {
    if (head == nullptr)
    {
      cout << "Nothing to delete." << endl;
      return;
    }
    else if (head->next == head)
    {
      delete head;
      head = nullptr;
      return;
    }

    Node *last = head;
    while (last->next != head)
    {
      last = last->next;
    }

    last->prev->next = head;
    head->prev = last->prev;
    delete last;
  }
};

int main()
{
  return 0;
}