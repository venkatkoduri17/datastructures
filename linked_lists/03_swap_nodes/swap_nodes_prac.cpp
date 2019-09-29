// C++ program to swap two given nodes of a linked list 
#include <iostream> 

using namespace std; 

// A linked list node class 
class Node { 
    public: 
        int data; 
        class Node* next; 

        // constructor 
        Node(int val, Node* next) 
            : data(val), next(next) 
        { 
        } 

        // print list from this 
        // to last till null 
        void printList() 
        { 

            Node* node = this; 

            while (node != NULL) { 

                cout << node->data; 
                node = node->next; 
            } 

            cout << endl; 
        } 
}; 

// Function to add a node 
// at the beginning of List 
void push(Node** head_ref, int new_data){ 
	// allocate node 
	(*head_ref) = new Node(new_data, *head_ref); 
} 

void swapNodes(Node** head_ref, int x, int y){
    if(x == y){
        return;
    }

    // cout << endl << endl;

    Node **a = NULL, **b = NULL;
    while(*head_ref){
        // cout << "Address is " << (*head_ref) << " --- Value is : " << (*head_ref)->data << endl;
        if((*head_ref)->data == x){
            a = head_ref;
        }
        if((*head_ref)->data == y){
            b = head_ref;
        }
        head_ref = &((*head_ref)->next);
    }

    if(a == NULL || b==NULL){
        cout << endl << "Invalid values" << endl;
        return;
    }

    (*a)->data = y;
    (*b)->data = x;

    return;    


}

// Driver code 
int main() 
{ 

	Node* start = NULL; 

	// The constructed linked list is: 
	// 1->2->3->4->5->6->7 
	push(&start, 7); 
	push(&start, 6); 
	push(&start, 5); 
	push(&start, 4); 
	push(&start, 3); 
	push(&start, 2); 
	push(&start, 1); 

	cout << "Linked list before swap : "; 
	start->printList(); 
    swapNodes(&start, 3,6);
    cout << "Linked list after swap : "; 
    start->printList(); 
} 
