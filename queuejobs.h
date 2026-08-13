#ifndef QUEUEJOBS_H
#define QUEUEJOBS_H
#include <iostream>
#include <string>

// Class Job 
class Job {
private:
    int numID;
    std::string userName;
    int pageNum;

public:
    Job(int newID = 0, std::string newName = "", int numPage = 0) {
        numID = newID;
        userName = std::move(newName);
        pageNum = numPage;
    }

    void display() const {
        std::cout << "[Job " << numID << " | " << userName << " | " << pageNum << " pages]";
    }
};

// Queue node class
template <typename T>
class qNode {
public:
    T data;
    qNode* next;
};

// create new node
template <typename T>
qNode<T>* new_node(T newData) {
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

// Printer class 
template <typename T>
class Printer {
public: 
    void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr) {
        qNode<T>* newNode = new_node(newData);

        if ((*frontPtr) == nullptr && (*backPtr) == nullptr) {
            *frontPtr = newNode;
            *backPtr = newNode;
            return;
        }

        (*backPtr)->next = newNode;
        *backPtr = newNode;
    }

    void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr) {
        if ((*frontPtr) == nullptr && (*backPtr) == nullptr) {
            std::cout << "The queue is empty" << std::endl;
            return;
        }

        qNode<T>* deleteTemp = *frontPtr;

        if ((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr) {
            *frontPtr = nullptr;
            *backPtr = nullptr;
            delete deleteTemp;
            return;
        }

        *frontPtr = (*frontPtr)->next;
        deleteTemp->next = nullptr;
        delete deleteTemp;
    }

    void displayQ(qNode<T>** frontPtr, qNode<T>** backPtr) {
        if ((*frontPtr) == nullptr && (*backPtr) == nullptr) {
            std::cout << "The queue is empty" << std::endl;
            return;
        }

        qNode<T>* curr = *frontPtr;
        while (curr != nullptr) {
            curr->data.display(); 
            if (curr->next != nullptr) {
                std::cout << " -> ";
            }
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};

#endif