
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList
{
    Node* head;

    Node* getLastNode()
    {
        Node* tmp = head;
        if (tmp == NULL) return NULL;
        while (tmp->next != NULL) tmp = tmp->next;
        return tmp;
    }

public:
    LinkedList() : head(NULL) {}

    bool isEmpty() { return head == NULL; }

    void prepend(int val)
    {
        if (head == NULL) head = new Node(val);
        else {
            Node* new_head = new Node(val);
            new_head->next = head;
            head = new_head;
        }
    }

    void append(int val)
    {
        Node* last = getLastNode();
        Node* newNode = new Node(val);
        if (last != NULL) { last->next = newNode; return; }
        head = newNode;
    }

    void deleteFirst()
    {
        if (head == NULL) return;
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    void deleteLast()
    {
        Node* prev = head;
        Node* current = prev->next;
        if (current == NULL) {
            delete head;
            head = NULL;
            return;
        }
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        delete current;
    }

    void reverse()
    {
        Node* temp_head = NULL;
        Node* current = head;
        while (current != NULL)
        {
            Node* temp_current = current;
            current = current->next;

            temp_current->next = temp_head;
            temp_head = temp_current;

        }
        head = temp_head;
    }

    void cyclicShift()
    {
        if (head == NULL) return;
        Node* temp_head = head;
        head = head->next;
        temp_head->next = NULL;
        Node* current = head;
        while (current->next != NULL)
            current = current->next;
        current->next = temp_head;
    }

    void cyclicShiftRight()
    {
        Node* prev = head;
        Node* current = prev->next;
        if (current == NULL) {
            return;
        }
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        current->next = head;
        head = current;

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
        if (temp == NULL) return false;
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        return true;
    }

    void remove(int findVal)
    {
        Node* temp = head;
        Node* prev = NULL;
        while (temp)
        {
            if (temp->data == findVal)
                break;
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) return;
        if (prev == NULL)
            deleteFirst();
        else
        {
            prev->next = prev->next->next;
            delete temp;
        }

    }

    void printAll()
    {
        Node* tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data;
            tmp = tmp->next;
        }
        cout << endl;
    }

    int getFirst()
    {
        return head->data;
    }

    int getLast()
    {
        return getLastNode()->data;
    }
};

int main()
{
    LinkedList myList;
    for (int i = 0; i < 10; i++)
        myList.append(i);
    /*myList.printAll();
    myList.deleteFirst();
    myList.printAll();
    myList.reverse();
    myList.printAll();
    myList.cyclicShift();
    myList.printAll();
    myList.cyclicShiftRight();
    myList.printAll();
    while(!myList.isEmpty())
    {
        myList.deleteLast();
        myList.printAll();
    }*/
    /*myList.insert(1,4);
    myList.printAll();
    myList.insert(1,9);
    myList.printAll();
    if (myList.insert(1,-1))
    myList.printAll();
    else cout<<"err";*/

    myList.remove(0);
    myList.printAll();
    myList.remove(9);
    myList.printAll();
    myList.remove(5);
    myList.printAll();
    return 0;
}