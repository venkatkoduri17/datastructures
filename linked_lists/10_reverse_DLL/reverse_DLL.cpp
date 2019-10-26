#include<iostream>
using namespace std;


struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }    
};

/* Function definitions */
void pushDLL(Node** , int);
void printDLL(Node**);
void reverseDLL(Node**);

/* handler function */
int main(){
    Node *a = NULL;

    /* Push Data into DLL */
    pushDLL(&a, 10);
    pushDLL(&a, 9);
    pushDLL(&a, 8);
    pushDLL(&a, 7);
    pushDLL(&a, 6);
    pushDLL(&a, 5);
    
    cout << endl << "Before reversing : ";
    printDLL(&a);

    cout << endl << "After reversing : ";
    reverseDLL(&a);
    printDLL(&a);

    return 0;
}


void pushDLL(Node** head_ref, int new_data){
    /* cout << endl << "pushDLL function is called"; */
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    // new_node->prev = NULL;

    /* Always handle excpetional cases */
    if((*head_ref) != NULL){
        (*head_ref)->prev = new_node;
    }
    
    (*head_ref) = new_node;
    
    return;
}

void printDLL(Node** head_ref){
    Node* temp = (*head_ref);
    Node* last;
    if((*head_ref) == NULL){
        cout << endl << "An empty DLL" << cout;
        return;
    }
    cout << endl << "Forward Order : ";
    while(temp != NULL){
        cout << temp->data << " -> ";        
        last = temp;
        temp = temp->next;
    }
    cout << " nullptr";

    cout << endl << "Reverse Order : ";
    temp = last;
    while(temp != NULL){
        cout << temp->data << " <- ";
        temp = temp->prev;
    }
    cout << " nullptr" << endl;
    return;

}

void reverseDLL(Node** head_ref){
    Node *before = NULL, *cur = NULL, *later = NULL, *temp = NULL;
    cur = (*head_ref);
    /* Base cases */
    if(*head_ref == NULL){
        return;
    }
    while(cur && cur->next){
        later = cur->next;
        cur->next = before;
        cur->prev = later;

        before = cur;
        cur = later;        
    }
    cur->next = before;
    cur->prev = NULL;

    (*head_ref) = cur;
    return;
}