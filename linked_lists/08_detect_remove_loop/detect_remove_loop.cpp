#include<iostream>
#include<unordered_set>
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
    return;
}

void printList(Node** head_ref){
    Node* temp = (*head_ref);
    cout << endl << "List : ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return;
}

void printListWithLoop(Node** head_ref){
    Node* temp = (*head_ref);
    cout << endl << "List : ";
    int count = 0;
    while(temp != NULL && count < 15){
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    return;
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


// Detects loop by using Floyds Algorithm
void detectLoopFloyd(Node** head_ref){
    // Floyd's Algorithm OR `tortoise and the hare algorithm`
    Node *slow = NULL, *fast = NULL;
    slow = (*head_ref);
    fast = (*head_ref);

    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            cout << endl << "Loop is detected";
            return;
        }
    }

    cout << endl << "No loop has been detected";
    return;
}

/* Detects loop using hash */
void detectLoopUsingHash(Node** head_ref){
    unordered_set<Node*> s;
    Node *temp = (*head_ref);
    while (temp != NULL){
        if(s.find(temp) != s.end()){
            cout << endl << "Loop has been detected using hasing : " << temp->data;
            return;
        }

        // insert the temp into hash
        s.insert(temp);
        temp = temp->next;
    }

    cout << endl << "No loop has been detected using hash";
    return;    

}
// 3->4->5->6->3
void removeLoop(Node* loop_node, Node** head_ref){
    int count = 1;
    // find the length of loop
    Node* temp = loop_node->next;
    while(temp != loop_node){
        count++;
        temp = temp->next;
    }
    cout << endl << "Loop length : " << count;

    Node* head = (*head_ref);
    temp = (*head_ref);
    while(count){
        temp = temp->next;
        count--;
    }

    cout << endl << "First : " << head->data;
    cout << endl << "Second : " << temp->data;
    /* Traverse the list starting from head and temp one node at a time simultaneously */
    while(head->next != temp->next){
        head = head->next;
        temp = temp->next;
    }

    /* Removing the loop */
    temp->next = NULL;

    return;
}


void detectAndRemoveUsingFloyd(Node** head_ref){
    // Floyd's Algorithm OR `tortoise and the hare algorithm`
    Node *slow = NULL, *fast = NULL;
    slow = (*head_ref);
    fast = (*head_ref);

    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            cout << endl << "Loop is detected";
            removeLoop(slow, head_ref);
            return;
        }
    }

    cout << endl << "No loop has been detected";
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
    reverseList(&a);

    printList(&a); 

    // Now set the loop
    a->next->next->next->next->next->next = a->next->next; 

    // Print the list with loop
    printListWithLoop(&a);

    detectLoopFloyd(&a);
    detectLoopUsingHash(&a);
    detectAndRemoveUsingFloyd(&a);

    cout << endl << "After removing the loop : ";
    printListWithLoop(&a);

    cout << endl << endl; 

}