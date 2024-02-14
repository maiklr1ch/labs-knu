#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

// Dynamic typed doubly-linked list
template <typename T>
class DoublyLinkedList
{
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList()
    {
        while (!isEmpty())
            shift();
    }

    // returns if list is empty
    bool isEmpty() const { return head == nullptr; }

    // add element to the head (prepends)
    void prepend(T val)
    {
        Node<T>* newNode = new Node<T>(val);
        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else {
            head = newNode;
            tail = newNode;
        }
    }

    // adds element to the tail (appends)
    void append(T val)
    {
        Node<T>* newNode = new Node<T>(val);
        if (tail != nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else {
            head = newNode;
            tail = newNode;
        }
    }

    // deletes the head element (shifts)
    void shift()
    {
        if (head == nullptr)
            return;
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;
    }

    // deletes the tail element (pops)
    void pop()
    {
        if (tail == nullptr)
            return;
        Node<T>* tmp = tail;
        tail = tail->prev;
        delete tmp;
        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;
    }

    // reverses doubly-linked list
    void reverse()
    {
        Node<T>* temp = head;
        Node<T>* tempNext;
        while (temp != nullptr) {
            tempNext = temp->next;
            temp->next = temp->prev;
            temp->prev = tempNext;
            temp = temp->prev;
        }

        Node<T>* tempTail = tail;
        tail = head;
        head = tempTail;
    }

    // shifts list to the left on one element
    void cyclicShiftLeft()
    {
        if (head == nullptr)
            return;
        tail->next = head;
        head->prev = tail;

        Node<T>* tempHead = head;
        head = head->next;
        tail = tempHead;
        head->prev = nullptr;
        tail->next = nullptr;
    }

    // shifts list to the right on one element
    void cyclicShiftRight()
    {
        if (head == nullptr)
            return;
        tail->next = head;
        head->prev = tail;

        Node<T>* tempTail = tail;
        tail = tail->prev;
        head = tempTail;
        head->prev = nullptr;
        tail->next = nullptr;
    }

    // returns index of element with given value
    int indexOf(T val) const
    {
        if (head == nullptr)
            return -1;
        Node<T>* temp = head;
        int index = 0;
        while (temp)
        {
            if (temp->data == val)
                return index;
            index++;
            temp = temp->next;
        }
        return -1;
    }

    // inserts new element after another one with given value
    bool insert(T val, T findVal)
    {
        Node* temp = head;
        while (temp)
        {
            if (temp->data == findVal)
                break;
            temp = temp->next;
        }
        if (temp == nullptr)
            return false;
        Node<T>* newNode = new Node<T>(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        if (newNode->next != nullptr)
            newNode->next->prev = newNode;
        return true;
    }

    // removes the element with given value
    bool remove(T findVal)
    {
        Node<T>* temp = head;
        Node<T>* tempPrev = nullptr;
        while (temp)
        {
            if (temp->data == findVal)
                break;
            tempPrev = temp;
            temp = temp->next;
        }
        if (temp == nullptr)
            return false;
        if (tempPrev == nullptr || temp->next == nullptr)
            shift();
        else
        {
            tempPrev->next = tempPrev->next->next;
            if (tempPrev->next != nullptr)
                tempPrev->next->prev = tempPrev;
            delete temp;
        }
        return true;
    }

    // prints all list
    void printAll() const
    {
        Node<T>* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // returns pointer to first list node
    Node<T>* getHeadNode()
    {
        return head;
    }

    // returns pointer to last list node
    Node<T>* getTailNode()
    {
        return tail;
    }
};