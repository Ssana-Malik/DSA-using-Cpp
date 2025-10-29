/* Task 3:
Write a program that demonstrate add, update, delete and print operation on circular linked list. 
a. You need to have a class Book with attributes(bookId:string, bookName:char,  bookPrice:double, bookAuthor:char and bookISBN:string). Also provide getters and setters for class private member variables. 
b. Make a class Node that contains book object as a class private member variable. 
The node class also contains Node next pointer.
c. Provide default and parameterized constructor, getters and setters for both book 
and pointer, 
d. Make a class BookList (act as a Doubly Circular LinkedList class) that provides following 
methods
	void addBook(bookId:string, bookName:char, bookPrice:double, bookAuthor:char, bookISBN:string) 
	void removeBook(bookId:string) 
	void updateBook(bookId:string, bookName:char, bookPrice:double, bookAuthor:char and bookISBN:string) 
	void printBooks() 
	void printBook(bookId:string) //it prints the required book
e. Write main function where you call all the methods in following order 
	Call addBook method 10 times
	Now call print book method 1 time
	Call remove book method 2 time (1 with valid bookId and other with invalid book id)
	Now call print book method 1 time
	Call updateBook method followed by print book*/
	
#include<iostream>
#include<sstream>
using namespace std;
class Book{
    string bookId, bookName, bookAuthor, bookISBN;
    double bookPrice;
    
    public:
    Book(){
	}
	
	Book(string id, string name, double price, string author, string isbn){
        bookId = id; 
		bookName = name; 
		bookPrice = price; 
		bookAuthor = author; 
		bookISBN = isbn;
    }
    
    // Getter
    
    string getId(){ 
		return bookId; 
	}
    
	string getName(){ 
		return bookName; 
	}
    
	string getAuthor(){ 
		return bookAuthor; 
	}
    
	string getISBN(){ 
		return bookISBN; 
	}
    
	double getPrice(){ 
		return bookPrice; 
	}
	
	//Setter
	
	void setBook(string id, string name, double price, string author, string isbn){
        bookId = id; 
		bookName = name; 
		bookPrice = price; 
		bookAuthor = author; 
		bookISBN = isbn;
    }
    
    void display() {
        cout<<"ID: "<<bookId<<", Name: "<<bookName<<", Price: "<<bookPrice<<", Author: "<<bookAuthor<<", ISBN: "<<bookISBN<<endl;
    }
};

struct Node{
    Book book;
    Node* next;
    Node* prev;

    Node(Book b) {
        book = b;
        next = prev = NULL;
    }
};

class BookList {
    Node* head;
    
public:
    BookList(){ 
		head = NULL; 
	}
	
	void addBook(string id, string name, double price, string author, string isbn){
		
        Book b(id, name, price, author, isbn);
        Node* newNode = new Node(b);
        
        if (!head) {
            head = newNode;
            head->next = head->prev = head;
        } 
		else {
            Node* last = head->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = head;
            head->prev = newNode;
        }
        cout<<"Book added.\n";
    }
    
    void removeBook(string id){
        if (!head){ 
			cout<<"Empty list.\n"; 
			return; 
		}
        
		Node* curr = head;
        do{
            if(curr->book.getId() == id){
                if(curr->next == curr){
                    delete curr;
                    head = NULL;
                } 
				else{
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    if(curr == head){
					head = curr->next;
					}
                    delete curr;
                }
                cout<<"Book "<<id<<" removed.\n";
                return;
            }
            
            curr = curr->next;
        } 
		while (curr != head);
        cout << "Book ID not found.\n";
    }

	void updateBook(string id, string name, double price, string author, string isbn) {
        if (!head){
			return;
		}	
        Node* curr = head;
        do{
            if(curr->book.getId() == id){
                curr->book.setBook(id, name, price, author, isbn);
                cout<<"Book updated.\n";
                return;
            }
            curr = curr->next;
        } 
		while (curr != head);
        cout<<"Book not found.\n";
    }
    
    void printBooks() {
        if (!head){
			cout<<"No books.\n"; 
			return; 
		}
		
        Node* curr = head;
        do{
            curr->book.display();
            curr = curr->next;
        } 
		while (curr != head);
    }

    void printBook(string id) {
        if (!head) return;
        Node* curr = head;
        do{
            if(curr->book.getId() == id){
                curr->book.display();
                return;
            }
            curr = curr->next;
        } 
		while (curr != head);
        cout<<"Book not found.\n";
    }
};

int main(){
	
    BookList bl;

    for (int j = 1; j <= 10; j++) {
        stringstream ss;
        ss << j;
        string num = ss.str();

        string id = "B" + num;
        string name = "Book" + num;
        string author = "Author" + num;
        string isbn = "ISBN" + num;
        double price = j * 100;

        bl.addBook(id, name, price, author, isbn);
    }

    cout << "\n--- Displaying Book B3 ---\n";
    bl.printBook("B3");

    cout << "\n--- Removing Books ---\n";
    bl.removeBook("B1");

    cout << "\n--- Displaying All Books ---\n";
    bl.printBooks();

    cout << "\n--- Updating Book B4 ---\n";
    bl.updateBook("B4", "NewBook4", 555, "NewAuthor4", "NewISBN4");

    cout << "\n--- Displaying Updated Book B4 ---\n";
    bl.printBook("B4");

    return 0;
}
	
