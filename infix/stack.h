#ifndef STACK_H   // Check if STACK_H is not defined
#define STACK_H   // Define STACK_H to avoid re-inclusion

#include <iostream>
using namespace std;

template <typename T>
class Stack
{
public:
    T stack[100];  // Fixed-size array to hold stack elements
    int index;

    Stack();  // Constructor declaration

    void emptyStack();  // Method to reset the stack

    bool isEmpty();  // Check if the stack is empty

    bool isFull();   // Check if the stack is full

    void push(T value);  // Push a value onto the stack

    T pop();  // Pop a value from the stack

    T onTop();  // Get the top value of the stack
};

// Template method implementations
template <typename T>
Stack<T>::Stack() {
    index = -1;  // Initialize the stack as empty
}

template <typename T>
void Stack<T>::emptyStack() {
    index = -1;  // Reset the stack to be empty
}

template <typename T>
bool Stack<T>::isEmpty() {
    return index == -1;  // Return true if stack is empty
}

template <typename T>
bool Stack<T>::isFull() {
    return index == 99;  // Return true if stack is full
}

template <typename T>
void Stack<T>::push(T value) {
    if (!isFull()) {
        stack[++index] = value;  // Add value to the stack
    } else {
        cout << "Stack is full." << endl;
    }
}

template <typename T>
T Stack<T>::pop() {
    if (!isEmpty()) {
        T val = stack[index];  // Save the value to be popped
        --index;  // Decrease the index (pop the element)
        return val;
    }
    return T();  // Return a default value for the type T if stack is empty
}

template <typename T>
T Stack<T>::onTop() {
    if (!isEmpty()) {
        return stack[index];  // Return the top element of the stack
    }
    return T();  // Return a default value for the type T if stack is empty
}

#endif  // END of the include guard
