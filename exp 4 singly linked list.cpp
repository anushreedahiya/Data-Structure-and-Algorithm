//EXP 4 (A) SINGLY LINKED LIST----
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
    void insert_start();
    void insert_end();
    void insert_intermediate();
    void delete_start();
    void delete_end();
    void delete_intermediate();
    void delete_val();
    void reverse();
	void concatenate(List &l2);
	void sort();
	void search(int value);
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
            listptr = temp = newNode;
        }
        else
        {
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
        cout << "Singly linked list: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
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
	newnode->next=temp->next;
	temp->next=newnode;
	newnode->data=val;
}

void List::delete_start()
{
	temp=listptr;
	listptr=temp->next;
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
	Node* q;
	int n, i;
	temp=listptr;
	cout<<"Enter the position of the node that you want to delete=";
	cin>>n;
	for (i=0; i<n-1; i++)
	{
		temp=temp->next;
	}
	q=temp->next;
	temp->next=q->next;
	delete(q);
}

void List::delete_val()
{
	Node* temp=listptr;
	Node* temp1;
	int val;
	cout<<"enter the value that you want to delete from the list=";
	cin>>val;
	if (temp->data==val)
	{
		listptr=listptr->next;
		delete(temp);
		return;
	}
	else
	{
		while(temp)   //temp!=NULL
		{
			if (temp->next && temp->next->data==val)
			{
				temp1=temp->next;
				temp->next=temp1->next;
				delete(temp1);
				return;
			}
			temp=temp->next;
		}
	}
}

void List::reverse()
{
	Node *temp, *ptr1, *ptr2; //ptr1=current node; ptr2= next node
	temp=listptr;
	ptr1=NULL;
	while (temp!=NULL)
	{
		ptr2=ptr1;
		ptr1=temp;
		temp=temp->next;
		ptr1->next=ptr2;
	}
	listptr=ptr1;
}

void List::concatenate(List &l2)
{
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
    }
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
    for (current=listptr; current!=NULL; current=current->next)
    {
        for (index=current->next; index!=NULL; index=index->next)
        {
            if (current->data > index->data)
            {
                tempValue=current->data;
                current->data=index->data;
                index->data=tempValue;
            }
        }
    }
}

void List::search(int value)
{
    temp=listptr;
    int position=0;
    while (temp!=NULL)
    {
        if (temp->data==value)
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
        cout <<"--------------------------------------------\n"
		" Enter choice:\n"
		" 1) Create a list \n"
		" 2) Display the list \n"
		" 3) Insert at beginning \n"
		" 4) insert at end \n"
		" 5) insert at intermediate \n"
		" 6) delete at beginning \n"
		" 7) delete at end \n"
		" 8) delete at intermediate \n"
		" 9) delete by value \n"
		" 10) reversing the list \n"
		" 11) creating a new linked list as list 2 \n"
		" 12) display list 2 \n"
		" 13) Concatenate List 2 to List 1 \n"
		" 14) Sorting List 1 \n"
		" 15) Search in List 1 \n"
		" 16) Exit \n ----------------------------------------------------\n";
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
            	l.delete_val();
            	break;
            case 10:
            	l.reverse();
            	break;
            case 11:
            	l2.create();
            	break;
            case 12:
            	l2.display();
            	break;
            case 13:
            	l.concatenate(l2);
            	break;
            case 14:
            	l.sort();
            	break;
            case 15:
				int searchValue;
            	cout << "Enter the value to search for in List 1: ";
            	cin >> searchValue;
            	l.search(searchValue);
            	break;
            case 16:
            	cout<<"Do you want to continue (y=1/n=0)=";
            	cin>>p;
            	break;
        }
    }
    return 0;
}



