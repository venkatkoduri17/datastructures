#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    };
};

void push(Node** head_ref, int data){
    Node* temp = new Node(data);
    temp->next = (*head_ref);
    (*head_ref) = temp;
}

void printList(Node** head_ref){
    Node* temp = (*head_ref);
    // cout << endl << "List : ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void reverseList(Node** head_ref){ 
    // Initialize current, previous and 
    // next pointers 
    Node* current = (*head_ref); 
    Node *prev = NULL, *next = NULL; 

    while (current != NULL) { 
        // Store next 
        next = current->next; 

        // Reverse current node's pointer 
        current->next = prev; 

        // Move pointers one position ahead. 
        prev = current; 
        current = next; 
    } 
    (*head_ref) = prev; 
}

Node* SortedMerge(Node* a, Node* b){

	Node* result = NULL; 

	/* Base cases */
	if (a == NULL) 
		return (b); 
	else if (b == NULL) 
		return (a); 

	/* Pick either a or b, and recur */
	if (a->data <= b->data) { 
		result = a; 
		result->next = SortedMerge(a->next, b); 
	} 
	else { 
		result = b; 
		result->next = SortedMerge(a, b->next); 
	} 
	return (result); 
}

void FrontBackSplit(Node* source, Node** frontRef, Node** backRef){
    Node *fast, *slow;
    slow = source;
    fast = source->next;
    /* Advance fast by two nodes and slow by one node at a time */
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }        
    }

    /* Break the linked list into two halves by making slow->next = NULL and assign the two arrays to frontRef and backRef respectively */
    (*frontRef) = source;
    (*backRef) = slow->next;
    slow->next = NULL;

    return;
}

void mergeSort(Node** head_ref){
    /* MergeSort(arr[], l,  r)
    If r > l
        1. Find the middle point to divide the array into two halves:  
                middle m = (l+r)/2
        2. Call mergeSort for first half:   
                Call mergeSort(arr, l, m)
        3. Call mergeSort for second half:
                Call mergeSort(arr, m+1, r)
        4. Merge the two halves sorted in step 2 and 3:
                Call merge(arr, l, m, r) */
    
    Node* head = (*head_ref);
    Node *a = NULL, *b = NULL;

    /* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)) { 
		return; 
	} 

    /* Split the array into two sub lists a and b */
    FrontBackSplit(head, &a, &b);

    /* Apply Merge sort on a and b */
    mergeSort(&a);
    mergeSort(&b);

    /* Apply sorted merge on a and b */
    (*head_ref) = SortedMerge(a, b);
}

int main(){

    // Node* a = NULL;
    // push(&a, 3);
    // push(&a, 5);
    // push(&a, 8);
    // push(&a, 13);
    // push(&a, 18);
    // push(&a, 23);
    // reverseList(&a);
    // cout << endl << "List A : ";
    // printList(&a);

    // Node* b = NULL;
    // push(&b, 5);
    // push(&b, 10);
    // push(&b, 15);
    // push(&b, 20);
    // push(&b, 25);
    // push(&b, 30);
    // reverseList(&b);
    // cout << endl << "List B : ";
    // printList(&b);

    // Node* r = SortedMerge(a, b);

    // cout << endl << "List R : ";
    // printList(&r);

    cout << "\nMerge Sort : ";
    Node* c = NULL;
    push(&c, 5);
    push(&c, 1);
    push(&c, 46);
    push(&c, 24);
    push(&c, 68);
    push(&c, 35);
    push(&c, 50);
    push(&c, 37);
    push(&c, 40);
    reverseList(&c);
    cout << endl << "List C : Before : ";
    printList(&c);

    mergeSort(&c);

    cout << endl << "List C : After : ";
    printList(&c);

    cout << "\n\n";

}