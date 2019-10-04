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

    Node* returnHead(){
        return head;
    }
};

void mergeSortedLikedLists(linkedList &l1, linkedList &l2, linkedList &res ){
    Node* head1 = l1.returnHead();
    Node* head2 = l2.returnHead();
    Node* head_res = res.returnHead();
    while(head1 != NULL || head2 != NULL){
        if(head1 == NULL){
            res.push(head2->data);
            head2 = head2->next;
        }else if(head2 == NULL){
            res.push(head1->data);
            head1 = head1->next;
        }else if(head1->data <= head2->data){
            res.push(head1->data);
            head1 = head1->next;
        }else if(head1->data > head2->data){
            res.push(head2->data);
            head2 = head2->next;
        }
    }
    res.reverse();
    return;
}

void printListOutside(linkedList &l1){
    cout << endl << "Printing Outside : " ;
    Node* current = l1.returnHead();
    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
}


int main(){
    linkedList l1, l2, res;
    
    // Build l1
    l1.push(20);
    l1.push(25);
    l1.push(15);
    l1.push(10);
    l1.push(5);
    
    cout << "L1 is : " ;
    l1.print();

    // Build l2
    l2.push(24);
    l2.push(16);
    l2.push(14);
    l2.push(12);

    cout << "L2 is : ";
    l2.print();

    cout << endl << "Res before : ";
    res.print();
    mergeSortedLikedLists(l1, l2, res);
    // printListOutside(l1);
    cout << endl << "Res After : ";
    res.print();
    
    cout << endl;
}
