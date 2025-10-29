/* Task 1: Circular linked List Task:
Make a circular link list and perform following
-Function called Insert before to add node at the beginning of Circular Linked list.
-Function called Insert After to add node at the end of Circular Linked list.
-Function called delete to del node in Circular Linked List .(consider all cases)*/

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    } 
	while (temp != head);
    cout << endl;
}

void insertBefore(Node*& head, int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = head; 
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void insertAfter(Node*& head, int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

void deletion(Node*& head, int pos) {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    // Case 1: deleting head
    if (pos == 1) {
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        if (head->next == head) { // only one node
            cout << "Deleting " << head->data << endl;
            delete head;
            head = NULL;
            return;
        }

        Node* del = head;
        head = head->next;
        last->next = head;
        cout << "Deleting " << del->data << endl;
        delete del;
        return;
    }

    // Case 2: deleting other positions
    Node* current = head;
    int count = 1;
    while (count < pos - 1 && current->next != head) {
        current = current->next;
        count++;
    }

    if (current->next == head) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* del = current->next;
    current->next = del->next;
    cout << "Deleting " << del->data << endl;
    delete del;
}

int main() {
    Node* node = NULL;
    int choice, val, pos;

    cout << "----MENU----" << endl;
    do {
        cout << "\n1. Insertion at beginning." << endl;
        cout << "2. Insertion at end." << endl;
        cout << "3. Deletion." << endl;
        cout << "4. Display." << endl;
        cout << "5. Exit." << endl << endl;

        cout << "Choose from the above options: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertBefore(node, val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            insertAfter(node, val);
            break;

        case 3:
            cout << "Enter position: ";
            cin >> pos;
            deletion(node, pos);
            break;

        case 4:
            cout << "\nList is: ";
            display(node);
            break;

        case 5:
            cout << "Exiting....." << endl;
            break;

        default:
            cout << "Invalid option!!!";
        }
    } 
	while (choice != 5);
    return 0;
}
