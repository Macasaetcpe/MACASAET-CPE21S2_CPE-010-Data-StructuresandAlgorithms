#ifndef SINGLY_LL_H
#define SINGLY_LL_H

template <typename T>
class musicList{
    public:
       T data;
       musicList<T>* prev = nullptr;
       musicList<T>* next = nullptr;
};

//creating a node:
template <typename T>
musicList<T> *AddSong(T newData){
    //dynamically allocate a new memory for the node
    musicList<T> *newNode = new musicList<T>;
    //store the data in the node
    newNode->data = newData;
    //point next and prev to null
    newNode->next = nullptr;
    newNode->prev = nullptr;
    //return the address of the newly created node

    return newNode;
}

template <typename T>
void playlistTraverse(musicList<T>* currentNode){

    musicList<T> *headNode; //temp store last node visited
    //check if the list is empty
    if(currentNode == nullptr){
        std::cout<<"The list is empty"<<std::endl;
        return;
    }
    headNode = currentNode;
    //move forward
    std::cout<<"Music Playlist"<<std::endl;
    while(currentNode != nullptr){
        std::cout<< currentNode->data<<" \n";
        currentNode = currentNode->next;
    }
    std::cout<<":End of Playlist:"<<std::endl;
    if(currentNode == nullptr){
        std::cout<< "--(Return to Start)--\n"<< headNode->data<<"\n";
    }
}

template <typename T>
void playlistInsertEnd(T newData, musicList<T>* currentHead){
    //create a new node
    musicList<T>* newNode  = AddSong(newData);
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
void deleteSong(T findData, musicList<T>** head){

    // if there is nothing to delete
    if (*head == nullptr) return;

    musicList<T>* currNode = *head;
    musicList<T>* prevNode = nullptr;

    // searching the node: 1. the node does not exist + we found data
    while (currNode != nullptr && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;

    }

    // if data not found currNode == nullPtr in the while loop
    if(currNode == nullptr){
        std::cout << "the data was not found\n" << std::endl;
        return;
    }

    // if data was found
    if(prevNode == nullptr){
        *head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }

    delete currNode;
}

#endif