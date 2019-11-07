/* C++ program to implement basic stack 
operations */
#include<iostream> 

using namespace std; 

#define MAX 1000 

class Stack { 
	int top; 

public: 
	int a[MAX]; // Maximum size of Stack 

	Stack() { top = -1; } 
	bool push(int x); 
	int pop(); 
	int peek(); 
	bool isEmpty(); 
    void displayItems();
}; 

bool Stack::push(int x) 
{ 
	if (top >= (MAX - 1)) { 
		cout << "Stack Overflow"; 
		return false; 
	} 
	else { 
		a[++top] = x; 
		cout << x << " pushed into stack\n"; 
		return true; 
	} 
} 

int Stack::pop() 
{ 
	if (top < 0) { 
		cout << "Stack Underflow"; 
		return 0; 
	} 
	else { 
		int x = a[top--]; 
		return x; 
	} 
} 
int Stack::peek() 
{ 
	if (top < 0) { 
		cout << "Stack is Empty"; 
		return 0; 
	} 
	else { 
		int x = a[top]; 
		return x; 
	} 
} 

bool Stack::isEmpty() 
{ 
	return (top < 0); 
} 

void Stack::displayItems(){
    cout << endl << "Items are : ";
    for (size_t i = 0; i <= top; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
    return;    
}

// Driver program to test above functions 
int main() 
{ 
	class Stack s; 
	s.push(10); 
	s.push(20); 
	s.push(30); 
	s.push(40); 
	s.push(50); 
	s.push(60); 
	cout << s.pop() << " Popped from stack\n"; 
    s.displayItems();

	return 0; 
} 
