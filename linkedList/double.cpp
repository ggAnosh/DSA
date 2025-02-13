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
      return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }

  void insertEnd(int val)
  {

    Node *newNode = new Node(val);

    if (head == nullptr)
    {
      head = newNode;
      return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
  }

  void deleteTop()
  {

    if (head == nullptr)
    {
      cout << "No elements to be deleted." << endl;
      return;
    }
    else if (head->next == nullptr)
    {
      delete head;
      head = nullptr;
      return;
    }
    else
    {
      Node *current = head;
      head = current->next;
      head->prev = nullptr;
      delete current;
    }
  }

  void deleteEnd()
  {
    if (head == nullptr)
    {
      cout << "No elements to delete." << endl;
      return;
    }
    else if (head->next == nullptr)
    {
      delete head;
      head = nullptr;
      return;
    }
    else
    {
      Node *current = head;
      while (current->next != nullptr && current->next->next != nullptr)
      {
        current = current->next;
      }
      delete current->next;
      current->next = nullptr;
      return;
    }
  }
};

int main()
{
  return 0;
}