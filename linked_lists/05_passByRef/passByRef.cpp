#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

struct linkedList{

    Node* head;

    // 
    linkedList(){
        head = NULL;
    }

    // add new data at the head
    void push(int data){
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    // Print the linked list
    void print(){
        Node* temp = head;
        cout << "Linked List : ";
        while (temp != NULL)
        {
            cout << " " << temp->data ;
            temp = temp->next;
        }
        cout << endl;                
    }

    void reverse(){
        Node* current = head;
        Node *prev = NULL, *next = NULL;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

void swapByPointer(int*, int*);
void swapByReference(int &, int &);

int main(){
    linkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);
    ll.push(5);    
    ll.print(); // Print before reversing
    ll.reverse(); // reverse the linked list
    ll.print(); // Print after reverse


    // Swap two numbers by pointers
    int a = 5, b = 10;
    cout << endl << "a = " << a << " : b = " << b;
    cout << endl << "Before Pointer : Addresses : &A = " << &a << " &B = " << &b;
    swapByPointer(&a, &b);
    cout << endl << "a = " << a << " : b = " << b;
    cout << endl << "After Pointer : Addresses : &A = " << &a << " &B = " << &b; 
    swapByReference(a,b);
    cout << endl << "a = " << a << " : b = " << b;
    cout << endl << "After Reference : Addresses : &A = " << &a << " &B = " << &b; 

    cout << endl;
}

void swapByPointer(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;    
}

void swapByReference(int &x, int &y){
    cout << endl << "swapByReference : Addresses : &A = " << &x << " &B = " << &y; 
    int temp = x;
    x = y;
    y = temp;
}