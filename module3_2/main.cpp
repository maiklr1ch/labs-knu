#include <iostream>

using namespace std;


enum class SwapDirection {
    LEFT,
    RIGHT
};

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    bool isEmpty() { return head == nullptr; }

    void prepend(int val)
    {
        Node* newNode = new Node(val);
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

    void append(int val)
    {
        Node* newNode = new Node(val);
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

    void deleteFirst()
    {
        if (head == nullptr)
            return;
        Node* tmp = head;
        head = head->next;
        delete tmp;
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;
    }

    void deleteLast()
    {
        if (tail == nullptr)
            return;
        Node* tmp = tail;
        tail = tail->prev;
        delete tmp;
        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;
    }

    void reverse()
    {
        Node* temp = head;
        Node* tempNext;
        while (temp != nullptr) {
            tempNext = temp->next;
            temp->next = temp->prev;
            temp->prev = tempNext;
            temp = temp->prev;
        }

        Node* tempTail = tail;
        tail = head;
        head = tempTail;
    }

    void cyclicShiftLeft()
    {
        if (head == nullptr)
            return;
        tail->next = head;
        head->prev = tail;

        Node* tempHead = head;
        head = head->next;
        tail = tempHead;
        head->prev = nullptr;
        tail->next = nullptr;
    }

    void cyclicShiftRight()
    {
        if (head == nullptr)
            return;
        tail->next = head;
        head->prev = tail;

        Node* tempTail = tail;
        tail = tail->prev;
        head = tempTail;
        head->prev = nullptr;
        tail->next = nullptr;
    }

    bool insert(int val, int findVal)
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
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        if (newNode->next != nullptr)
            newNode->next->prev = newNode;
        return true;
    }

    void remove(int findVal)
    {
        Node* temp = head;
        Node* tempPrev = nullptr;
        while (temp)
        {
            if (temp->data == findVal)
                break;
            tempPrev = temp;
            temp = temp->next;
        }
        if (temp == nullptr)
            return;
        if (tempPrev == nullptr || temp->next == nullptr)
            deleteFirst();
        else
        {
            tempPrev->next = tempPrev->next->next;
            if (tempPrev->next != nullptr)
                tempPrev->next->prev = tempPrev;
            delete temp;
        }
    }

    void printAll()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void swap(int val, SwapDirection swapWith) // swapping elements with value (int val), with element to the side of SwapDirection (LEFT / RIGHT)
    {
        Node* temp = head;

        while(temp)
        {
            if(temp->data == val)
            {
                Node* changeTemp;
                if(swapWith == SwapDirection::RIGHT && temp->next)
                {
                    Node* tempPrev = temp->prev;
                    changeTemp = temp->next;
                    temp->next = changeTemp->next;
                    temp->prev = changeTemp;
                    changeTemp->next = temp;
                    changeTemp->prev = tempPrev;
                    if(temp->next)
                        temp->next->prev = temp;
                    if(changeTemp->prev)
                        changeTemp->prev->next = changeTemp;
                    if(changeTemp == tail)
                        tail = temp;
                    if(temp == head)
                        head = changeTemp;
                } else if(swapWith == SwapDirection::LEFT && temp->prev)
                {
                    Node* tempNext = temp->next;
                    changeTemp = temp->prev;
                    temp->next = changeTemp;
                    temp->prev = changeTemp->prev;
                    changeTemp->next = tempNext;
                    changeTemp->prev = temp;
                    if(temp->prev)
                        temp->prev->next = temp;
                    if(changeTemp->next)
                        changeTemp->next->prev = changeTemp;
                    if(changeTemp == head)
                        head = temp;
                    if(temp == tail)
                        tail = changeTemp;
                }
                break;
            }
            temp = temp->next;
        }
    }

    int getFirst()
    {
        return head->data;
    }

    int getLast()
    {
        return tail->data;
    }
};

int main()
{
    DoublyLinkedList l;
    for(int i = 1; i < 8; i++)
        l.append(i);
    cout << "> Initial: ";
    l.printAll();

    cout << "\n> Changing 5 with left element: ";
    l.swap(5, SwapDirection::LEFT);
    l.printAll();
    cout << "> Changing 2 with right element: ";
    l.swap(2, SwapDirection::RIGHT);
    l.printAll();
    cout << "> Changing 2 again with right element: ";
    l.swap(2, SwapDirection::RIGHT);
    l.printAll();
    cout << "> Changing 1 with left element (no changes because 1 is the first): ";
    l.swap(1, SwapDirection::LEFT);
    l.printAll();
    return 0;
}
