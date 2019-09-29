#include <iostream>

using namespace std;

// Define Linked list Node
class Node {
    public:
        int data;
        Node* next;
};

Node* addAtEnd(Node* n, int new_data){

    // cout << endl << endl << "Address of head : " << n;
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;

    Node* temp = NULL;
    Node* parent = NULL;
    temp = n;
    if(temp != NULL){
        // cout << endl << "Begin Traversing : ";
        while(temp != NULL ){
            // cout << " " << temp->data;
            parent = temp;
            temp = temp->next;
        }

        parent->next = new_node;

        return n;
    }else{
        return new_node;
    }

}

Node* addAtStart(Node* n, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = n;
    
    return new_node;

}

int getCount(Node* n){
    int count = 0;
    while(n != NULL){
        count++;
        n = n->next;
    }
    return count;
}

void printList(Node* n){
    cout << endl << "List is : ";
    while(n != NULL){
        cout << " " << n->data;
        n = n->next;
    }
}

int main(){
    
    // Define the header Node pointer
    Node* head = NULL; // head is a pointer to the Node. Initialised to point to NULL

    // Add the nodes to the Linked list;
    /* Use push() to construct below list 
	1->2->1->3->1 */
    head = addAtEnd(head, 1);  
    head = addAtEnd(head, 2);  
    head = addAtEnd(head, 3);  
    head = addAtEnd(head, 4);  
    head = addAtEnd(head, 5); 

    head = addAtStart(head, 0);  
    head = addAtStart(head, -1);  
    head = addAtStart(head, -2);  
    head = addAtStart(head, -3);  
    head = addAtStart(head, -4);  
    head = addAtStart(head, -5); 

    printList(head);
    cout << endl << "Count is : " << getCount(head);
    cout << endl << endl;
    return 0;
}