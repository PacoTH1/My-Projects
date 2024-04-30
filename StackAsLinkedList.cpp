#include <iostream>

using namespace std; 

// Singly Linked List class
class Node {
	public:
		// Attributes
		int Value;
		Node* Next;
		
		// Constructor
		Node(int value) {
			Value=value;
		}
};

// Stack class
class Stack {
	public: 
		// Attributes
		Node* Head;
		
		// Methods
		Stack() {
			Head=NULL;
		}
		
		Stack(Node* head) {
			Head=head;
		}
		
		void Push(int value);
		int Pop();
	
};

void Stack::Push(int value) {
	Node* node=new Node(value);
	node->Next=Head;
	Head=node;
}

int Stack::Pop() {
	int value=0;
	if(Head!=NULL) {
		value=Head->Value;
		Head=Head->Next;
		return value;
	}else{
		cout<<"Error-The list is empty\n"<<endl;
		return -1;
	}
}

void printStack(Node* node) {
	while(node!=NULL) {
		cout<<node->Value<<endl;
		node=node->Next;
	}
}


int main() {
	Stack stack1;
	stack1.Push(3);
	stack1.Push(10);
	stack1.Push(245);
	stack1.Push(6);
	stack1.Push(24);
	
	printStack(stack1.Head);
	
	stack1.Pop();
	
	cout<<"\n\nStack after removing one object: "<<endl;
	printStack(stack1.Head);

	
	return 0;
}
