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
void quickSort(Node**);
void _quickSort(Node*, Node*);
Node* partition(Node*, Node*);
void swap(int*, int*);

/* handler function */
int main(){
    Node *a = NULL;

    /* Push Data into DLL */
    // pushDLL(&a, 76);
    // pushDLL(&a, 86);
    pushDLL(&a, 18);
    pushDLL(&a, 18);
    pushDLL(&a, 18);
    // pushDLL(&a, 25);
    // pushDLL(&a, 1);
    // pushDLL(&a, 12);
    
    cout << endl << "Before reversing : ";
    printDLL(&a);

    cout << endl << "After Quick Sorting : ";
    quickSort(&a);
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
        cout << endl << "An empty DLL" << endl;
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

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;

    return;
}


Node*  partition(Node* l, Node* h){
    int pivot = h->data;
    Node* i = l->prev;
    for(Node* j = l; j != h; j = j->next){
        if(j->data <= pivot){
            i = (i == NULL) ? l : i->next;
            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL) ? l : i->next;
    swap(&(i->data), &(h->data));
    return i;

}

void _quickSort(Node* l, Node* h){

    if(h != NULL && l != h && l != h->next){

        Node* p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    } 
    
}


void quickSort(Node** head_ref){
    Node* lastNode = (*head_ref);
    while(lastNode && lastNode->next){
        lastNode = lastNode->next;
    }

    _quickSort((*head_ref), lastNode);

}