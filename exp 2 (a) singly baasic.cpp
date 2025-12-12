// BAsic singly linked list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class List
{
    Node *listptr, *temp;
public:
    List()
    {
        listptr = NULL;
        temp = NULL;
    }
    void create();
    void display();
};

void List::create()
{
    int val;
    char choice;
    do
    {
        cout << "Enter the value to be stored in the node: ";
        cin >> val;
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        if (listptr == NULL)
        {
            listptr = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        cout << "Do you want to add another node (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

void List::display()
{
    Node* temp = listptr;
    if (temp == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        cout << "Linked list: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    int p = 1, ch;
    List l;
    while (p == 1)
    {
        cout << "Enter choice:\n 1) Create a list \n 2) Display the list \n";
        cin >> ch;
        switch (ch)
        {
            case 1:
                l.create();
                break;
            case 2:
                l.display();
                break;
        }
    }
    return 0;
}

