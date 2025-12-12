//EXP 5 (A) DOUBLY LINKED LIST----
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
        listptr = NULL;
        temp = NULL;
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
    void sort();
};

void List::create()
{
	int n, val, i;
	cout<<"Enter total number of nodes that you want to create for the list=";
	cin>>n;
	for(i=0; i<n; i++)
	{
		Node* newNode=new Node;
		cout<<"Enter the value to store in the node=";
		cin>>val;
		newNode->data=val;
		newNode->next=NULL;
		if (listptr == NULL)
        {
        	newNode->prev=NULL;
            listptr = temp = newNode;
        }
        else
        {
        	newNode->prev=temp;;
            temp->next = newNode;
            temp = newNode;
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
        cout << "Doubly linked list: ";
        cout<<"NULL <-> ";
        while (temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout<<" NULL "<<endl;
    }
}

void List::insert_start()
{
	Node* newnode=new Node;
	int val;
	cout<<"Enter the value to add at the beginning of the list=";
	cin>>val;
    newnode->data=val;
	newnode->next=listptr;
	listptr->prev = newnode;
	listptr=newnode;
}

void List::insert_end()
{
	Node* newnode=new Node;
	int val;
	temp=listptr;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	cout<<"Enter the value to add at the end of the list=";
	cin>>val;
	newnode->prev=temp;
	temp->next=newnode;
	
	temp->data=val;
	temp->next=NULL;
	
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
	temp=listptr;
	listptr=temp->next;
    if (listptr!=NULL)
    {
        listptr->prev = NULL;
    }
	delete(temp);
}

void List::delete_end()
{
	Node* q;
	temp=listptr;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	q=temp->next;
	temp->next=NULL;
	delete(q);
}

void List::delete_intermediate()
{
	Node* temp; //temp should be on the node that is to be deleted
	int n, i;
	temp=listptr;
	cout<<"Enter the position of the node that you want to delete=";
	cin>>n;
	for (i=0; i<n-1; i++)
	{
		temp=temp->next;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	delete(temp);
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
    if (l2.listptr==NULL)
    {
        return; // Nothing to concatenate from list2
    }
    if (listptr==NULL)
    {
        listptr=l2.listptr;
    }
    else
    {
        temp=listptr;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=l2.listptr;
        l2.listptr->prev=temp;
    }
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

void List::sort()
{
    if (listptr == NULL)
    {
        cout << "List is empty. Nothing to sort." << endl;
        return;
    }
    Node *current, *index;
    int tempValue;

    for (current = listptr; current != NULL; current = current->next)
    {
        for (index = current->next; index != NULL; index = index->next)
        {
            if (current->data > index->data)
            {
                tempValue = current->data;
                current->data = index->data;
                index->data = tempValue;
            }
        }
    }
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
		" 14) Sort List \n"
		" 15) Exit \n ----------------------------------------------------\n";
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
            	l.sort();
            	break;
            case 15:
            	cout<<"Do you want to continue (y=1/n=0)=";
            	cin>>p;
            	break;
        }
    }
    return 0;
}




/*

// Function to insert a node with data at odd positions in the list
void insert_at_odd(int data)
{
    Node* newNode = new Node(data);
    temp=listptr;
    if (temp==NULL)
	{
        temp=newNode; // If the list is empty, the new node becomes the head
        return;
    }
    Node* current=temp;
    int position=1;
    while (current!=NULL)
	{
        if (position % 2 != 0)
		{ // Check if the position is odd
            if (current->prev ==NULL)
			{
                newNode->next = current;
                current->prev = newNode;
                temp= newNode;
            }
			else
			{
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
            }
            return;
        }

        position++;
        current = current->next;
    }

    // If no odd position is found, insert at the end
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete a node at odd positions from the list
void deleteAtOdd()
{
    if (temp==NULL)
	{
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Node* current=temp;
    int position=1;

    while (current!=NULL)
	{
        if (position%2!=0)
		{ // Check if the position is odd
            if (current->prev==NULL)
			{
                temp=current->next;
                if (head!=NULL)
				{
                    temp->prev=NULL;
                }
                delete current;
                return;
            }
			else
			{
                current->prev->next = current->next;
                if (current->next!=NULL)
				{
                    current->next->prev=current->prev;
                }
                delete current;
                return;
            }
        }

        position++;
        current = current->next;
    }
}

// Function to insert a node with data at even positions in the list
void insertAtEven(int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode; // If the list is empty, the new node becomes the head
        return;
    }

    Node* current = head;
    int position = 1;

    while (current != nullptr) {
        if (position % 2 == 0) { // Check if the position is even
            if (current->prev == nullptr) {
                newNode->next = current;
                current->prev = newNode;
                head = newNode;
            } else {
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
            }
            return;
        }

        position++;
        current = current->next;
    }

    // If no even position is found, insert at the end
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete a node at even positions from the list
void deleteAtEven() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Node* current = head;
    int position = 1;

    while (current != nullptr) {
        if (position % 2 == 0) { // Check if the position is even
            if (current->prev == nullptr) {
                head = current->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
                delete current;
                return;
            } else {
                current->prev->next = current->next;
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
        }

        position++;
        current = current->next;
    }
}


*/

