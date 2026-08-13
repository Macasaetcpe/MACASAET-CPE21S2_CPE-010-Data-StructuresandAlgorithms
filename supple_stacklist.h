#ifndef STACK_LIST_H
#define STACK_LIST_H

#include <iostream>

// Class node that contains data and the next pointer
template <typename T>
class Node {
public:
    T data;
    Node* next;
};

// Global pointer for the top of the stack
template <typename T>
Node<T>* head = nullptr;

// push
template <typename T>
void push(T newData) {
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = head<T>;
    head<T> = newNode;
}

// pop
template <typename T>
T pop() {
    if (head<T> == nullptr) {
        std::cout << "Stack underflow." << std::endl;
        return T(); 
    }

    Node<T>* temp = head<T>;
    T tempVal = temp->data;
    head<T> = head<T>->next;
    delete temp;
    return tempVal;
}

// isEmpty
template <typename T>
bool isEmpty() {
    return head<T> == nullptr;
}

// top
template <typename T>
void Top() {
    if (isEmpty<T>()) {
        std::cout << "Stack underflow" << std::endl;
        return;
    }
    std::cout << "Top of Stack: " << head<T>->data << std::endl;
}

// Check if open and close brackets match
template <typename T>
bool isMatching(T open, T close) {
    if ((open == '(' && close == ')') ||
        (open == '[' && close == ']') ||
        (open == '{' && close == '}')) {
        std::cout << open << " and " << close << " are matching" << std::endl;
        return true;
    } else {
        std::cout << "ERROR: " << open << " and " << close << " are NOT matching" << std::endl;
        return false;
    }
}

// displayAll
template <typename T>
void displayALL() {
    if (head<T> == nullptr) {
        std::cout << "Stack underflow\n";
        return;
    }
    std::cout << "Displaying the stack:\n";
    Node<T>* temp = head<T>;
    while (temp != nullptr) {
        std::cout << temp->data << "\n";
        temp = temp->next;
    }
    std::cout << "\n";
}

#endif