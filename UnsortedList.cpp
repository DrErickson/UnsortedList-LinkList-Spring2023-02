

#include "UnsortedList.h"

template<class T>
UnsortedList<T>::UnsortedList() {
    length = 0;
    head = nullptr;
    currPos = nullptr;
}

template<class T>
UnsortedList<T>::~UnsortedList() {
    MakeEmpty();
}

template<class T>
void UnsortedList<T>::MakeEmpty() {
    while (head != nullptr) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    length = 0;
    currPos = nullptr;
}

template<class T>
bool UnsortedList<T>::IsFull() const {
    try {
        Node* tmp = new Node;
        delete tmp;
    }
    catch (std::bad_alloc error) {
        return true;
    }

    return false;
}

template<class T>
int UnsortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool UnsortedList<T>::Contains(T someItem) {
    Node* currNode = head;

    while (currNode != nullptr) {
        if (currNode->value == someItem) {
            return true;
        }
        currNode = currNode->next;
    }

    return false;
}

template<class T>
void UnsortedList<T>::AddItem(T item) {
    Node* nodeToInsert = new Node;
    nodeToInsert->value = item;
    nodeToInsert->next = head;
    head = nodeToInsert;
    ++length;
}

template<class T>
void UnsortedList<T>::DeleteItem(T item) {
    Node* currNode = head;
    Node* prevNode = nullptr;

    while (currNode != nullptr) {
        if (currNode->value == item) {
            if (prevNode != nullptr) {
                prevNode->next = currNode->next; // middle, end
            } else {
                head = currNode->next; // begin
            }
            delete currNode;
            --length;
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

template<class T>
void UnsortedList<T>::ResetIterator() {
    currPos = head;
}

template<class T>
T UnsortedList<T>::GetNextItem() {
    T itemToReturn = currPos->value;
    currPos = currPos->next;
    return itemToReturn;
}

