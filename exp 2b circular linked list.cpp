//EXP 2(B): CIRCULAR LINKED LIST
//inserting, deleting element; reversing, concatenate
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
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
            head = NULL;
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
        Node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == head) {
            delete head;
            head = NULL;
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
    Node* prev = NULL;
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
   void reverse() {
    if (!head) {
        std::cout << "Circular Linked List is empty." << std::endl;
        return;
    }

    Node* prev = NULL;
    Node* current = head;
    Node* nextNode;

    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != head);

    head = prev;
}

 void concatenate(CircularLinkedList& cll2) {
        if (!head) {
            head = cll2.head;
        } else if (!cll2.head) {
            
        } else {
            Node* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            tail->next = cll2.head;

            Node* cll2Tail = cll2.head;
            while (cll2Tail->next != cll2.head) {
                cll2Tail = cll2Tail->next;
            }
            cll2Tail->next = head;
        }
        cll2.head = NULL; // Detach the second list
    }

    
    void display(){
    		if(!head){
    			std::cout<<"Circular linked list is empty"<<std::endl;
    			return;
    		}
    		Node* current = head;
    		do{
    			std::cout<<current->data<<"->";
    			current = current->next;
    		}while(current!= head);
    		std::cout<<"Head"<<std::endl;
    	}
};

int main() {
    CircularLinkedList cll;
    CircularLinkedList cll2;
    int numElements;
    cout << "Enter the number of elements: ";
    cin >> numElements;

    for (int i = 0; i < numElements; ++i) {
        int value;
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        cll.insertAtEnd(value);
    }

    std::cout << "Circular Linked List1: ";
    cll.display();
    
    int numElements2;
    cout << "Enter the number of elements for the second list: ";
    cin >> numElements2;

    for (int i = 0; i < numElements2; ++i) {
        int value;
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        cll2.insertAtEnd(value);
    }
    cout << "Circular Linked List2: ";
    cll.display();
    while (true) {
        cout << "Menu: \n 1. Insert at Start \n 2. Insert at End \n 3. Insert at Middle \n 4. Delete at Start \n"
        " 5. Delete at End \n 6. Delete at Middle \n 7. Reverse \n 8. Concatenate Lists \n 9. Exit";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int value;
                cout << "Enter value: ";
                cin >> value;
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
    
            case 7: {
                cll.reverse();
                 std::cout << "Circular Linked List elements reversed: ";
                 cll.display();
                 break;
            }
            case 8: {
                cll.concatenate(cll2);
                std::cout << "Updated Circular Linked List elements after concatenation: ";
                cll.display();
                break;
            }
            
            case 9:
     
                return 0;
            
            default:
                std::cout << "Invalid choice. Please select again." << std::endl;
        }
    }

    return 0;
}



