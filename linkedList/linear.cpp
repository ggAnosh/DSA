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

class Singly
{

public:
  Node *head;

  Singly()
  {
    head = nullptr;
  }

  void insertTop(int val)
  {
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
      head = newNode;
      cout << "Element has been place inside of the node." << endl;
      return;
    }

    newNode->next = head;
    head = newNode;
    cout << "Element has been place inside of the node." << endl;
  }

  void insertEnd(int val)
  {

    Node *newNode = new Node(val);

    if (head == nullptr)
    {
      head = newNode;
      cout << "Element has been placed at the end." << endl;
      return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    cout << "Element has been place at the end." << endl;
  }

  void deleteTop()
  {
    if (head->next == nullptr)
    {
      Node *temp = head;
      delete head;
      head = nullptr;
      return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
    cout << "Element has been deleted from the top." << endl;
  }

  void deleteEnd()
  {
    Node *temp = head;
    while (temp->next != nullptr && temp->next->next == nullptr)
    {
      temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
  }
};

int main()
{
  return 0;
}