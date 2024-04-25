#include <iostream>

using namespace std;


class Node {
	public:
		// Attributes
		int Value;
		Node* Next;
		
		// Methods
		Node* linkedListLookUp(Node* head, int elementNumber);
		void linkedListInsertAfter(Node* previous, Node* newNode);
		Node* linkedListInsert(Node* head, int index, int value);
		Node* linkedListDelete(Node* head, int index);
};


Node* Node::linkedListLookUp(Node* head, int elementNumber) {
	Node* current = head;
	int count = 0;
	
	while(count<elementNumber && current != NULL) {
		current = current->Next;
		count++;
	}
	return current;
	
}

void Node::linkedListInsertAfter(Node* previous, Node* newNode) {
	newNode->Next=previous->Next;
	previous->Next=newNode; 
}

Node* Node::linkedListInsert(Node* head, int index, int value) {
	// Inserting a new head node
	if(index==0) {
		Node* newHead=new Node();
		newHead->Value=value;
		newHead->Next=head;
		return newHead;
	}
	
	// Inserting something at the middle or
	// after the end of the list
	Node* current=new Node();
	current=head;
	Node* previous=new Node();
	previous=NULL;
	int count=0;
	
	while(count<index&&current!=NULL) {
		previous=current;
		current=current->Next;
		count++;
	}
	
	// Checks if the index points to a position
	// that goes beyond the size of the list
	if(count<index) {
		cout<<"ERROR-Index out of bounds"<<endl;
		return NULL;
	}
	
	Node* newNode=new Node();
	newNode->Value=value;
	newNode->Next=previous->Next;
	previous->Next=newNode;
	
	return head;
}

Node* Node::linkedListDelete(Node* head, int index) {
	// Checks whether the list is empty
	if(head==NULL)
		return NULL;
		
	if(index==0) {
		Node* newHead = new Node();
		newHead=head->Next;
		head->Next=NULL;
		return newHead;
	}
	
	Node* current = new Node();
	current=head;
	Node* previous = new Node();
	previous=NULL;
	int count=0;
	
	while(count<index&&current!=NULL) {
		previous=current;
		current=current->Next;
		count++;
	}
	
	if(current!=NULL) {
		previous->Next=current->Next;
		current->Next=NULL;
	}else{
		cout<<"ERROR-Index out of bounds"<<endl;
		return NULL;
	}
	
	return head;
	
	
}


void printList(Node* node) {
	while(node!=NULL) {
		cout<<node->Value<<endl;
		node=node->Next;
	}
}


int main() {
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();
	Node* fourth = new Node();
	
	head->Value = 1;
	head->Next = second;
	
	second->Value = 2;
	second->Next = third;
	
	third->Value = 3;
	third->Next = fourth;
	
	fourth->Value = 4;
	fourth->Next = NULL;
	
	printList(head);
		
	cout<<"\n"<<head->linkedListLookUp(head, 0)->Value<<endl;
	Node* obtainedValue = head->linkedListLookUp(head, 0);

	cout<<obtainedValue->Value<<endl;
	
	// Inserting a new value after a given one (first insertion method)
	/*
	cout<<"\nInserting a new value"<<endl;
	Node* newNode = new Node();
	newNode->Value = 10;
	
	head->linkedListInsertAfter(second, newNode);
	
	printList(head); */
	
	// Second insertion method
	cout<<"\nInserting a new value (second method)"<<endl;
	head->linkedListInsert(head,2,12);
	printList(head);
	
	// Deleting a value
	cout<<"\nList after deletion"<<endl;
	head->linkedListDelete(head, 2);
	printList(head);
	
	
	return 0;
}
