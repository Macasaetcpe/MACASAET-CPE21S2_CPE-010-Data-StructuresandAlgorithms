#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
class DoubleList{
    public:
       T data;
       DoubleList<T>* prev = nullptr;
       DoubleList<T>* next = nullptr;
};

//creating a node:
template <typename T>
DoubleList<T> *CreateNewNode(T newData){
    //dynamically allocate a new memory for the node
    DoubleList<T> *newNode = new DoubleList<T>;
    //store the data in the node
    newNode->data = newData;
    //point next and prev to null
    newNode->next = nullptr;
    newNode->prev = nullptr;
    //return the address of the newly created node

    return newNode;
}

template <typename T>
void dllTraverse(DoubleList<T>* currentNode){

    DoubleList<T> *tail; //temp store last node visited
    //check if the list is empty
    if(currentNode == nullptr){
        std::cout<<"The list is empty"<<std::endl;
        return;
    }
    std::cout<<"Forward: \n";
    //move forward
    while(currentNode != nullptr){
        std::cout<< currentNode->data<<" ";
        tail = currentNode;
        currentNode = currentNode->next;
    }
    //add a next line
    std::cout<<std::endl;
    //move backward
    std::cout<<"Back: \n";
    while(tail != nullptr){
        std::cout<< tail->data<<" ";
        tail = tail->prev;
    }
}

//insertion at the head
template <typename T>
void dllInsertHead(T newData, DoubleList<T> ** currentHead){
    //creating a new node
    DoubleList<T>* newNode = CreateNewNode(newData);

    //new node should point to the current head
    newNode->next = *currentHead;
    //current head should point back to the new node
    (*currentHead)->prev = newNode;
    //update pointer head
    *currentHead = newNode;
}

template <typename T>
void dllInsertEnd(T newData, DoubleList<T>* currentHead){
    //create a new node
    DoubleList<T>* newNode  = CreateNewNode(newData);
    //traverse until we reach the last node
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }

    //connect the last node to the new node
    currentHead->next  = newNode;

    //connect the new node back to the last node
    newNode->prev = currentHead;
}

template <typename T>
void dllGeneralInsert(T newData, DoubleList<T>* prevNode){
    if(prevNode == nullptr){
        std::cout<<"Previous value cannot be null"<<std::endl;
        return;
    }
    DoubleList<T>* newNode  = CreateNewNode(newData);
    DoubleList<T>* nextNode;

    newNode->data = newData;
    nextNode = prevNode->next;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    nextNode->prev = newNode;
    newNode->prev = prevNode;
    
}

template <typename T>
void dllDeleteNode(T findData, DoubleList<T>** head){
    // if there is nothing to delete
    if (*head == nullptr) return;
    DoubleList<T>* currNode = *head;
    DoubleList<T>* prevNode = nullptr;
    DoubleList<T>* nodeNext;
    // searching the node: 1. the node does not exist + we found data
    while (currNode != nullptr && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;
    }
    nodeNext = currNode->next;
    // if data not found currNode == nullPtr in the while loop
    if(currNode == nullptr){
        std::cout << "the data was not found\n" << std::endl;
        return;
    }

    // if data was found
    if(prevNode == nullptr){
        *head = currNode->next;
        nodeNext = currNode;
    } else if (nodeNext != nullptr) {
        prevNode->next = currNode->next;
        nodeNext->prev = currNode->prev; 
    }
    delete currNode;
}


#endif