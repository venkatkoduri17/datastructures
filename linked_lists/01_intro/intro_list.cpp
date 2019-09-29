// A simple C++ program for traversal of a linked list 
#include <iostream> 
using namespace std; 

class Node { 
    public: 
        int data; 
        Node* next; 
}; 

// This function prints contents of linked list 
// starting from the given node 
void printList(Node* n) 
{
    cout << "Linked list output is : " << endl; 
	while (n != NULL) { 
        // cout << "Address : " << n << " ";
		cout << " -- Value : " << n->data << endl; 
		n = n->next; 
	} 
    cout << endl;
} 

Node* addToList(Node* n, int new_data){
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = NULL;

	Node* temp = NULL;
	Node* parent = NULL;

	temp = n;
	while(temp != NULL){
		parent = temp;
		temp = temp->next;
	}

	parent->next = new_node;

	return n;

}

// Driver code 
int main() 
{
    // head, second, third are three pointer variables of the given Node type objects 
	Node* head = NULL; 
	Node* second = NULL; 
	Node* third = NULL; 

    // Print the value of head
    cout << "Head : " << head << endl;

	// allocate 3 nodes in the heap 
    // All the three pointers will now point 
    // new Node will return the address of the memory block allocated to the Node element
	head = new Node(); 
	second = new Node(); 
	third = new Node();

    // Print the value of head
    cout << "Head : " << head << endl; 

	head->data = 1; // assign data in first node 
	head->next = second; // Link first node with second 

	second->data = 2; // assign data to second node 
	second->next = third; 

	third->data = 3; // assign data to third node 
	third->next = NULL; 

	printList(head); 
	head = addToList(head, 4);
	printList(head);

	return 0; 
} 

// This is code is contributed by rathbhupendra 
