#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void printNode(Node* n){
    cout << endl << endl << "Print the node : "<< endl;
    
    cout << "Address is : " << n << endl;
    cout << "Value is : " << n->data << endl;
    cout << "Next Node address : " << n->next << endl;
    return;
}

void printList(Node* head){
    cout << endl << "Print the list : ";
    while(head){
        // cout << "Address is : " << head << "  --- Value : " << head->data << "  ---   Next node Address : " << head->next << endl;
        cout << " " << head->data;
        head = head->next;
    }
    return;
}

void pushToList(Node** head_ref, int new_data){
    // cout << endl << "pushToList called : ";
    Node* node = new Node(new_data);
    node->next = (*head_ref);
    (*head_ref) = node;
}

void reverseList(Node** head_ref){
    // Input :  A->B->C->D , Output : D->C->B->A
    Node* prev = NULL;
    Node* curr = NULL;
    Node* next = NULL;

    curr = (*head_ref);
    while(curr){
        // printNode(curr);
        next = curr->next;
        curr->next = prev;
        // printList(prev);
        prev = curr;
        curr = next;
    }
    (*head_ref) = prev;
    return;
}

int main(){
    // cout << "This is to reverse a linked list" << endl;
    Node* start = new Node(5);
    // printNode(start);
    start->next = new Node(6);
    printList(start);
    pushToList(&start, 4);
    pushToList(&start, 3);
    pushToList(&start, 2);
    pushToList(&start, 1);
    printList(start);
    reverseList(&start);
    printList(start);  

    cout << endl;

    return 0; 

}