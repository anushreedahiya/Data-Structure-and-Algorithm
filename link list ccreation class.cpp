// ANUSHREE DAHIYA
// CS- A1
// PRN: 22070122023
// link list creation
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
class Node
{
	public:
		int data;
		Node* next;
};
class List:public Node
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
};

void List::create()
{
	int n, i, x;
	cout<<"\n enter the total number of nodes:";
	cin>>n;
	for (i=0; i<n; i++)
	{
		Node *newnode=new Node;
		cout<<"\n enter the data:";
		cin>>x;
		newnode->data=x;
		newnode->next=NULL;
		if (listptr==NULL)
		{
			listptr=newnode;
			temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
	}
}

void List::display()
{
}

int main()
{
	int p=1, ch;
	List l;
	cout<<"Anushree Dahiya \n CS-A1 \n PRN=22070122023";
	while (p==1)
	{
		cout<<"\n Enter choice:\n 1) create\n 2) display\n";
		cin>>ch;
		switch (ch)
		{
			case 1:
				l.create();
				break;
			case 2:
				l.display();					
				break;
				break;
		}
		cout<<"\n\n PRESS 1 TO CONTINUE";
		cin>>p;
	}
}

