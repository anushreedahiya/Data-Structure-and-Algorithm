// EXP 6: circular linked list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

class List
{
    Node *listptr, *temp;
public:
    List()
    {
        listptr=NULL;
        temp=NULL;
    }
    void create();
    void display();
    void insert_start();
    void insert_end();
    void insert_intermediate();
    void delete_start();
    void delete_end();
    void delete_intermediate();
    void reverse();
    void concatenate(List &l2);
    void search(int value);
};

void List::create()
{
    int n, val, i;
    cout<<"Enter total number of nodes that you want to create for the list=";
    cin>>n;
    for (i=0; i<n; i++)
    {
        Node* newNode = new Node;
        cout<<"Enter the value to store in the node=";
        cin>>val;
        newNode->data=val;
        newNode->next=NULL;
        if (listptr==NULL)
        {
            listptr=newNode;
			temp=newNode;
            newNode->next=listptr; 
        }
        else
        {
            while (temp->next!=listptr)
            {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=listptr;
        }
    }
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
        cout << "Circular linked list: ";
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != listptr);
        cout << temp->data << " -> " << listptr->data << " (Back to the beginning)" << endl;
    }
}

void List::insert_start()
{
    Node* newnode = new Node;
    int val;
    cout << "Enter the value to add at the beginning of the list=";
    cin >> val;
    newnode->data = val;
    if (listptr == NULL)
    {
        newnode->next = newnode;
        listptr = newnode;
    }
    else
    {
        Node* lastNode = listptr;
        while (lastNode->next != listptr)
        {
            lastNode = lastNode->next;
        }
        newnode->next = listptr;
        listptr = newnode;
        lastNode->next = newnode;
    }
}

void List::insert_end()
{
    Node* newnode = new Node;
    int val;
    cout << "Enter the value to add at the end of the list=";
    cin >> val;
    newnode->data = val;
    if (listptr == NULL)
    {
        newnode->next = newnode;
        listptr = newnode;
    }
    else
    {
        Node* firstNode = listptr;
        Node* lastNode = listptr;
        while (lastNode->next != listptr)
        {
            lastNode=lastNode->next;
        }
        lastNode->next=newnode;
        newnode->next=firstNode;
        newnode->prev=lastNode;
    }
}


void List::insert_intermediate()
{
	Node* newnode=new Node; //creating a new node
	int val, i=0, n;
	temp=listptr;
	cout<<"enter the position where you want to add the value=";
	cin>>n;
	while (i!=n-1)
	{
		temp=temp->next;
		i++;
	}
	cout<<"Enter the value to add at the intermediate position of the list=";
	cin>>val;
	newnode->data=val;
	
	newnode->next = temp->next;
	temp->next->prev = newnode;
	temp->next = newnode;
	newnode->prev = temp;
}

void List::delete_start()
{
    if (listptr == NULL)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (listptr->next == listptr)
    {
        delete listptr;
        listptr = NULL;
    }
    else
    {
        Node* firstNode = listptr;
        Node* lastNode = listptr;
        while (lastNode->next != listptr)
        {
            lastNode = lastNode->next;
        }
        listptr = firstNode->next;
        listptr->prev = lastNode;
        lastNode->next = listptr;
        delete firstNode;
    }
}

void List::delete_end()
{
    if (listptr == NULL)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (listptr->next == listptr)
    {
        delete listptr;
        listptr = NULL;
    }
    else
    {
        Node* lastNode = listptr;
        Node* secondLastNode = NULL;
        while (lastNode->next != listptr)
        {
            secondLastNode = lastNode;
            lastNode = lastNode->next;
        }
        secondLastNode->next = listptr;
        listptr->prev = secondLastNode;
        delete lastNode;
    }
}

void List::delete_intermediate()
{
	int n;
	cout<<"Enter the position of the node that you want to delete=";
	cin>>n;
    if (listptr == NULL)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (n<0)
    {
        cout << "Invalid position. Position should be a non-negative integer." << endl;
        return;
    }
    if (n==0)
    {
        cout<<"Cannot delete the first node using this function. Use delete_start() instead." << endl;
        return;
    }
    Node* currentNode=listptr;
    Node* prevNode=NULL;
    int currentPosition=0;
    do
    {
        prevNode=currentNode;
        currentNode=currentNode->next;
        currentPosition++;

        if (currentPosition==n)
        {
            prevNode->next=currentNode->next;
            currentNode->next->prev=prevNode;
            delete currentNode;
            return;
        }
    } while (currentNode != listptr);
    cout << "Node at position " << n << " not found." << endl;
}

void List::reverse()
{
    Node* current = listptr;
	Node* nextNode = NULL;
	Node* prevNode = NULL;
    while (current!=NULL)
    {
		nextNode = current->next; // Store the next node.
        // Reverse the links.
        current->next = prevNode;
        current->prev = nextNode;
        // Move to the next node.
        prevNode = current;
        current = nextNode;
    }
    listptr = prevNode;
}

void List::concatenate(List &l2)
{
    if (l2.listptr == NULL)
    {
        return; // Nothing to concatenate from list2
    }
    if (listptr == NULL)
    {
        listptr = l2.listptr;
    }
    else
    {
        Node* temp1 = listptr;
        Node* temp2 = l2.listptr;
        while (temp1->next != listptr)
        {
            temp1 = temp1->next;
        }
        while (temp2->next != l2.listptr)
        {
            temp2 = temp2->next;
        }
        temp1->next = l2.listptr;
        temp2->next = listptr;
        listptr->prev = temp2;
        l2.listptr->prev = temp1;
    }
    l2.listptr = NULL;
}

void List::search(int value)
{
    temp = listptr;
    int position = 0;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << "Value " << value << " found at position " << position << " in the list." << endl;
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << "Value " << value << " not found in the list." << endl;
}

int main()
{
    int p = 1, ch;
    List l, l2;
    while (p == 1)
    {
        cout <<"--------------------------------------------\n Enter choice:\n"
		" 1) Create a list \n"
		" 2) Display the list \n"
		" 3) Insert at beginning \n"
		" 4) insert at end \n"
		" 5) insert at intermediate \n"
		" 6) delete at beginning \n"
		" 7) delete at end \n"
		" 8) delete at intermediate \n"
		" 9) reversing the list \n"
		" 10) create a new list as list 2 \n"
		" 11) displaying list 2 \n"
		" 12) Concatenate with another List \n"
		" 13) Search for a value \n"
		" 14) Exit \n ----------------------------------------------------\n";
        cin >> ch;
        switch (ch)
        {
            case 1:
                l.create();
                break;
            case 2:
                l.display();
                break;
            case 3:
            	l.insert_start();
            	break;
            case 4:
            	l.insert_end();
            	break;
            case 5:
            	l.insert_intermediate();
            	break;
            case 6:
            	l.delete_start();
            	break;
            case 7:
            	l.delete_end();
            	break;
            case 8:
            	l.delete_intermediate();
            	break;
            case 9:
            	l.reverse();
            	break;
            case 10:
            	l2.create();
            	break;
            case 11:
            	l2.display();
            	break;
            case 12:
            	l.concatenate(l2);
            	break;
            case 13:
            	int searchValue;
            	cout << "Enter the value to search for: ";
            	cin >> searchValue;
            	l.search(searchValue);
            	break;
            case 14:
            	cout<<"Do you want to continue (y=1/n=0)=";
            	cin>>p;
            	break;
        }
    }
    return 0;
}







/*
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = nullptr;
    }

    void create()
	{
    	int data;
    	int n, i;
    	cout << "";
    	cin >> n;
    	head = NULL;
    	Node* last = NULL;
    	for (i = 0; i < n; i++)
		{
    	    cout << "Enter data for node " << i + 1 << ": ";
        	cin >> data;
    	    Node* newNode = new Node(data);
        	newNode->next = NULL;
        	if (head == NULL)
			{
            	head = newNode;
            	last = newNode;
            	head->next = head;
        	}
			else
			{
            	last->next = newNode;
            	last = newNode;
            	last->next = head;
        	}	
    	}
	}

    void display()
	{
	    if (head == NULL)
		{
	        cout << "Empty list" << endl;
	        return;
	    }
	    Node* temp = head;
	    do
		{
	        cout << temp->data;
	        if (temp->next != head)
			{
	            cout << "->";
	        }
	        temp = temp->next;
	    } while (temp != head && temp != NULL);
	    cout << endl;
	}
	
    void insertAtBeg(int data) {
        Node* temp = new Node(data);
        if (head == nullptr) {
            head = temp;
            head->next = head;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }

            temp->next = head;
            head = temp;
            last->next = head;
        }
    }

    void insertAtEnd(int data) {
        Node* temp = new Node(data);
        if (head == nullptr) {
            head = temp;
            head->next = head;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }

            last->next = temp;
            temp->next = head;
        }
    }

    void insertAtIntermediate(int position, int data) {
        Node* temp = head;
        int count = 1;

        while (count < position - 1) {
            temp = temp->next;
            count++;
        }

        Node* nodeToInsert = new Node(data);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }

    void deleteAtIntermediate(int position) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        int count = 1;

        while (count < position - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (temp->next == head) {
            cout << "Position exceeds the length of the list. Cannot delete." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    void deleteAtBeg() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = head;
        if (temp->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }

            head = temp->next;
            delete temp;
            last->next = head;
        }
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        delete temp;
    }

    void reverseList() {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != head);
    
    head->next = prev;
    head = prev;
}


    void concatenateLists(Node* list2) {
    if (head == nullptr) {
        head = list2;
        return;
    }

    if (list2 == nullptr) {
        return;
    }

    Node* temp1 = head;
    while (temp1->next != head) {
        temp1 = temp1->next;
    }

    Node* temp2 = list2;
    while (temp2->next != list2) {
        temp2 = temp2->next;
    }

    temp1->next = list2;
    temp2->next = head;
    head = list2;  
}
};

int main() {
    CircularLinkedList list;
    CircularLinkedList list2;

   cout << "Enter the number of elements in the list 1: ";
    list.create();

    cout << "Enter the number of elements in the list 2: ";
    list2.create();

    cout << "Circular Linked List 1: ";
    list.display();
    cout << "Circular Linked List 2: ";
    list2.display();

    int choice, data, position;

    while (true) {
        cout << "Circular Linked List Operations:" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at an intermediate position" << endl;
        cout << "4. Delete a node at an intermediate position" << endl;
        cout << "5. Delete at Beginning" << endl;
        cout << "6. Delete at End" << endl;
        cout << "7. Display the linked list" << endl;
        cout << "8. Reverse Of the List" << endl;
        cout << "9. Concatenate Lists" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                list.insertAtBeg(data);
                cout << "Circular Linked List: ";
                list.display();
                break;
            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                list.insertAtEnd(data);
                cout << "Circular Linked List: ";
                list.display();
                break;
            case 3:
                cout << "Enter position and data to insert at an intermediate position: ";
                cin >> position >> data;
                list.insertAtIntermediate(position, data);
                cout << "Circular Linked List: ";
                list.display();
                break;
            case 4:
                cout << "Enter position to delete a node: ";
                cin >> position;
                list.deleteAtIntermediate(position);
                cout << "Circular Linked List: ";
                list.display();
                break;
            case 5:
                list.deleteAtBeg();
                cout << "Circular Linked List after deletion at beginning: ";
                list.display();
                break;
            case 6:
                list.deleteAtEnd();
                cout << "Circular Linked List after deletion at end: ";
                list.display();
                break;
            case 7:
                cout << "Circular Linked List: ";
                list.display();
                break;
            case 8:
                cout << "Reverse List:";
                list.reverseList();
                list.display();
                break;
            case 9:
                list.concatenateLists(list2.head);
                cout << "Lists Concatenated." << endl;
                cout << "Concatenated List:";
                list.display();
                break;
                
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
*/
