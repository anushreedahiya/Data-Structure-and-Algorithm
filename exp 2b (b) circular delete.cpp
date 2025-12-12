//part of main code

//EXP 2 (B): CIRCULAR LINKED LIST
// deleting element at the beginning, end, intermediate value
#include <iostream>

class Node{
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertAtMiddle(int index, int value) {
        if (index < 0) {
            std::cout << "Invalid index for insertion." << std::endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
                if (temp == head) {
                    std::cout << "Invalid index for insertion." << std::endl;
                    return;
                }
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void deleteAtStart() {
        if (!head) {
            std::cout << "Circular Linked List is empty." << std::endl;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        if (head == temp) {
            delete head;
            head = nullptr;
        } else {
            temp->next = head->next;
            delete head;
            head = temp->next;
        }
    }
    
    void deleteAtEnd() {
        if (!head) {
            std::cout << "Circular Linked List is empty." << std::endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == head) {
            delete head;
            head = nullptr;
        } else {
            prev->next = head;
            delete temp;
        }
    }
    
    void deleteAtMiddle(int index) {
    if (!head) {
        std::cout << "Circular Linked List is empty." << std::endl;
        return;
    }

    if (index < 0) {
        std::cout << "Invalid index for deletion." << std::endl;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;
    for (int i = 0; i < index; ++i) {
        prev = temp;
        temp = temp->next;
        if (temp == head) {
            std::cout << "Invalid index for deletion." << std::endl;
            return;
        }
    }

    if (temp == head) {
        // If the node to be deleted is the head node
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = head->next;
        delete head;
        head = tail->next;
    } else {
        prev->next = temp->next;
        delete temp;
    }
}
    void display() {
        if (!head) {
            std::cout << "Circular Linked List is empty." << std::endl;
            return;
        }

        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }
};

int main() {
    CircularLinkedList cll;

    int numElements;
    std::cout << "Enter the number of elements: ";
    std::cin >> numElements;

    for (int i = 0; i < numElements; ++i) {
        int value;
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> value;
        cll.insertAtEnd(value);
    }

    std::cout << "Circular Linked List elements: ";
    cll.display();

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Insert at Start" << std::endl;
        std::cout << "2. Insert at End" << std::endl;
        std::cout << "3. Insert at Middle" << std::endl;
        std::cout << "4. Delete at Start" << std::endl;
        std::cout << "5. Delete at End" << std::endl;
        std::cout << "6. Delete at Middle" << std::endl;
        std::cout << "7. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                std::cout << "Enter value: ";
                std::cin >> value;
                cll.insertAtStart(value);
                std::cout << "Updated Circular Linked List elements: ";
                cll.display();
                break;
            }
            case 2: {
                int value;
                std::cout << "Enter value: ";
                std::cin >> value;
                cll.insertAtEnd(value);
                std::cout << "Updated Circular Linked List elements: ";
                cll.display();
                break;
            }
            case 3: {
                int index, value;
                std::cout << "Enter index: ";
                std::cin >> index;
                std::cout << "Enter value: ";
                std::cin >> value;
                cll.insertAtMiddle(index, value);
                std::cout << "Updated Circular Linked List elements: ";
                cll.display();
                break;
            }
            case 4: {
                cll.deleteAtStart();
                std::cout << "Updated Circular Linked List elements: ";
                cll.display();
                break;
            }
            case 5: {
                cll.deleteAtEnd();
                std::cout << "Updated Circular Linked List elements: ";
                cll.display();
                break;
            }
            case 6: {
                int index;
                std::cout << "Enter index: ";
                std::cin >> index;
                cll.deleteAtMiddle(index);
                std::cout << "Updated Circular Linked List elements: ";
                cll.display();
                break;
    }
            case 7:
                return 0;
            default:
                std::cout << "Invalid choice. Please select again." << std::endl;
        }
    }

    return 0;
}

//EXP 2 (B): CIRCULAR LINKED LIST
//insertion of an element at the beginning, end, intermediate
#include <iostream>
class Node
{
public:
    int data;
    Node* next;

    Node(int value)
	{
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList
{
	private:
    	Node* head;
    	
	public:
    	CircularLinkedList()
		{
    	    head = nullptr;
    	}
    	void insertAtStart(int value)
		{
        	Node* newNode = new Node(value);
        	if (!head)
			{
            	head = newNode;
            	head->next = head;
        	}
			else
			{
            	Node* temp = head;
            	while (temp->next != head)
				{
            	    temp = temp->next;
            	}
            	temp->next = newNode;
            	newNode->next = head;
            	head = newNode;
        	}
    	}
    	
		void insertAtEnd(int value)
		{
        	Node* newNode = new Node(value);
        	if (!head)
			{
            	head = newNode;
            	head->next = head;
        	}
			else
			{
            	Node* temp = head;
            	while (temp->next != head)
				{
                	temp = temp->next;
            	}
            	temp->next = newNode;
            	newNode->next = head;
        	}
    	}	
    	
    	void insertAtMiddle(int index, int value)
		{
        	if (index < 0)
			{
            	std::cout << "Invalid index for insertion." << std::endl;
            	return;
        	}
			Node* newNode = new Node(value);
        	if (!head)
			{
            	head = newNode;
            	head->next = head;
        	}
			else
			{
        	    Node* temp = head;
        	    for (int i = 0; i < index - 1; ++i)
				{
        	        temp = temp->next;
        	        if (temp == head)
					{
        	            std::cout << "Invalid index for insertion." << std::endl;
                    return;
                	}
            	}
            	newNode->next = temp->next;
            	temp->next = newNode;
        	}
    	}
		
		void display()
		{
        	if (!head)
			{
            	std::cout << "Circular Linked List is empty." << std::endl;
            	return;
        	}
        	Node* temp = head;
        	do
			{
            	std::cout << temp->data << " ";
            	temp = temp->next;
        	}
			while (temp != head);
        		std::cout << std::endl;
    	}
};

int main()
{
    CircularLinkedList cll;

    int numElements;
    std::cout << "Enter the number of elements: ";
    std::cin >> numElements;

    for (int i = 0; i < numElements; ++i)
	{
        int value;
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> value;
        cll.insertAtEnd(value);
    }

    std::cout << "Circular Linked List elements: ";
    cll.display();

    while (true)
	{
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Insert at Start" << std::endl;
        std::cout << "2. Insert at End" << std::endl;
        std::cout << "3. Insert at Middle" << std::endl;
        std::cout << "4. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
		{
            case 1:
			{
                int value;
                std::cout << "Enter value: ";
                std::cin >> value;
                cll.insertAtStart(value);
                std::cout << "Updated Circular Linked List elements: ";
                cll.display();
                break;
            }
            case 2:
			{
                int value;
                std::cout << "Enter value: ";
                std::cin >> value;
                cll.insertAtEnd(value);
                std::cout << "Updated Circular Linked List elements: ";
                cll.display();
                break;
            }
            case 3:
			{
                int index, value;
                std::cout << "Enter index: ";
                std::cin >> index;
                std::cout << "Enter value: ";
                std::cin >> value;
                cll.insertAtMiddle(index, value);
                std::cout << "Updated Circular Linked List elements: ";
                cll.display();
                break;
            }
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice. Please select again." << std::endl;
        }
    }
    return 0;
}




