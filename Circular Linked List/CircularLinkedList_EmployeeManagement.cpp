/* Task 2: Data Entry Operator in a company implementation
Suppose, you are working as a Data Entry Operator in a company. You have created a dataset that contains the names of N employees. 
Then your supervisor wants you to add, deleted, update, look/search for a particular employee by name.(Consider, every name in the data set is unique).
Now your task is to write a program using circular singly Link List Data structure which will help you to add, del, 
find out the details which your supervisor is looking for.
If an operation is performed successfully then print an appropriate messages “added/deleted/found successfully”.*/

#include<iostream>
using namespace std;

struct Node {
    string name;
    Node* next;
};

void display(Node* head) {
    if (head == NULL) {
        cout<<"No employees.\n";
        return;
    }
    Node* temp = head;
    do {
        cout<<temp->name<<" ";
        temp = temp->next;
    } 
	while (temp != head);
    cout<<endl;
}

void addEmployee(Node*& head, string empName) {
    Node* newNode = new Node();
    newNode->name = empName;

    if (head == NULL) {
        head = newNode;
        newNode->next = head; 
        cout<<empName<<" added successfully.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    {
        temp->next = newNode;
        newNode->next = head;
    }

    cout<<empName<<" added successfully.\n";
}
void deleteEmployee(Node*& head, string empName) {
    if (head == NULL) {
        cout<<"List is empty, nothing to delete!\n";
        return;
    }

    Node* curr = head;
    Node* prev = NULL;


    if (curr->next == head && curr->name == empName) {
        delete curr;
        head = NULL;   
        cout<<"Deleted successfully.\n";
        return;
    }

    do {
        if (curr->name == empName) break;
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    if (curr->name != empName) {
        cout<<empName<<" not found!\n";
        return;
    }

    if (curr == head) {
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        delete curr;
        cout<<"Deleted successfully.\n";
    }
 
    else {
        prev->next = curr->next;
        delete curr;
        cout<<"Deleted successfully.\n";
    }
}


void searchEmployee(Node* head, string empName) {
    if (head == NULL) {
        cout<<"List is empty.\n";
        return;
    }

    Node* temp = head;
    do {
        if (temp->name == empName) {
            cout<<empName<<" found successfully.\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout<<empName<<" not found.\n";
}

void updateEmployee(Node* head, string oldName, string newName) {
    if (head == NULL) {
        cout<<"List is empty.\n";
        return;
    }

    Node* temp = head;
    do {
        if (temp->name == oldName) {
            temp->name = newName;
            cout<<"Updated "<<oldName<<" to "<<newName<<" successfully.\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout<<oldName<<" not found!\n";
}

int main() {
    Node* head = NULL;
    int choice;
    string name, newName;

    cout<<"---- Employee Record ----\n";
    do {
        cout<<"\n1. Add employee\n";
        cout<<"2. Delete employee\n";
        cout<<"3. Search employee\n";
        cout<<"4. Update employee\n";
        cout<<"5. Display employees\n";
        cout<<"6. Exit\n";

        cout<<"\nChoose option: ";
        cin>>choice;

        switch (choice) {
        case 1:
            cout<<"Enter employee name: ";
            cin>>name;
            addEmployee(head, name);
            break;

        case 2:
            cout<<"Enter employee name to delete: ";
            cin>>name;
            deleteEmployee(head, name);
            break;

        case 3:
            cout<<"Enter employee name to search: ";
            cin>>name;
            searchEmployee(head, name);
            break;

        case 4:
            cout<<"Enter old name: ";
            cin>>name;
            cout<<"Enter new name: ";
            cin>>newName;
            updateEmployee(head, name, newName);
            break;

        case 5:
            cout<<"Employees: ";
            display(head);
            break;

        case 6:
            cout<<"Exiting...\n";
            break;

        default:
            cout<<"Invalid option!\n";
        }
    } 
	while (choice != 6);

    return 0;
}

