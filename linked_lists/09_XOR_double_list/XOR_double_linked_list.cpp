#include<iostream>
/* #include<vector>
#include<cstdint> */
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    };
};

Node* XOR(Node* prev,Node* next){
    return (Node *)((uintptr_t)(prev) ^ (uintptr_t)(next));
}

void push(Node** head_ref, int data){
    Node* temp = new Node(data);

    /* XOR of the previous and the next node */
    temp->next = XOR(NULL, (*head_ref));

    if((*head_ref)){
        (*head_ref)->next = XOR(temp, XOR(NULL, (*head_ref)->next));
    }

    (*head_ref) = temp;
    return;
}

void printList(Node** head_ref){
    
    Node* curr = (*head_ref);
    Node* prev = NULL;
    Node* next;
    cout << endl << "List : ";
    while(curr != NULL){
        cout << curr->data << " -> ";
        next = XOR(prev, curr->next);
        prev = curr;
        curr = next;
    }
    cout << "nullptr";
    return;
}

int main(){

    Node* a = NULL;
    push(&a, 3);
    push(&a, 5);
    push(&a, 8);
    push(&a, 13);
    push(&a, 18);
    push(&a, 23);

    printList(&a); 
    
    cout << endl << endl;
    return 0;
}