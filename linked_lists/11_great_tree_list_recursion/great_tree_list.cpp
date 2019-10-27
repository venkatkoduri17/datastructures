#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

/* Function definitions */

void printCList(Node *head){
    cout << endl << "Circular Linked list : ";
    Node *temp = head;
    if(head == NULL){
        cout << endl << "Empty list";
    }
    
    do{
        cout << temp->data << " -> ";
        temp = temp->right;
    }while(temp != head);

    cout << endl << endl;
    return;
}

Node* concatenate(Node* leftList, Node* rightList){

    // cout << endl << "concatenate function has been called : ";


    /* Handle edge cases */
    if(leftList == NULL){
        // cout << endl << "leftList is NULL";
        return rightList;
    }
    if(rightList == NULL){
        // cout << endl << "rightList is NULL";
        return leftList;
    }

    // Store the last Node of left List 
    Node *leftLast = leftList->left; 
  
    // Store the last Node of right List 
    Node *rightLast = rightList->left; 
  
    // Connect the last node of Left List 
    // with the first Node of the right List 
    leftLast->right = rightList; 
    rightList->left = leftLast; 
  
    // Left of first node points to 
    // the last node in the list 
    leftList->left = rightLast; 
  
    // Right of last node refers to the first 
    // node of the List 
    rightLast->right = leftList; 
  
    return leftList;
}


Node* bTreeToCList(Node* root){

    
    /* Base case */
    if(root == NULL){
        return root;
    }

    // cout << endl << "bTreeToCList function called : " << root->data;

    /* Recursively convert left and right subtrees into cycles */
    Node *left = bTreeToCList(root->left);
    Node *right = bTreeToCList(root->right);

    /* Make circular linked list of the root node */
    root->left = root->right = root;

    /* First concatenete left CList with root Node and then result with the right Clist */
    return concatenate(concatenate(left, root), right);
}

int main(){
    /* Building the B tree */
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    Node *head = bTreeToCList(root);
    printCList(head);
    return 0;
}