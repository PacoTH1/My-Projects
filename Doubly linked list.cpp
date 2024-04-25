#include <iostream>

using namespace std;

// structs are public by default
class Node {
	public: 
		int data;
		Node* prev;
		Node* next;
		
		// Constructor
		Node (int val) {
			// Initialize all attributes
			prev=NULL;
			data=val;
			next=NULL;
		}
	
};

void printListForward(Node* head) {
	Node* currentNode=head;
	while(currentNode!=NULL) {
		cout<<currentNode->data<<" ";
		currentNode=currentNode->next;
	}
}

// In this method the head only gets modified inside
// of the function.
Node* getTail(Node* head, Node* tail){
	while(head!=NULL) {
		tail=head;
		head=head->next;
	}
	return tail;
}

void printListBackwards(Node* head,Node* tail) {
	if(tail==NULL) {
		//Node* tail=new Node();
		tail=getTail(head, tail);
	}
	while(tail!=NULL) {
		cout<<tail->data<<" ";
		tail=tail->prev;
	}
}

// When a function receives a pointer, it actually
// receives a copy of it. So, to modify the 
// original one, a pointer to a pointer (**)
// needs to be passed
void insertAtFront(Node** head, int data) {
	// Create a new node with the given
	// data
	Node* newNode=new Node(data);
	
	newNode->prev=NULL;
	//(*head) allows us to access the value, pointed by head, itself
	newNode->next=(*head);
	
	if((*head)!=NULL){
		(*head)->prev=newNode;
	}
	
	(*head)=newNode;
	
}

void insertAfter(Node* current, int data) {
	Node* newNode=new Node(data);
	
	newNode->next=current->next;
	current->next=newNode;
	newNode->prev=current;
	
	if(newNode->next!=NULL) {
		newNode->next->prev=newNode;
	}
	
	
}

// My method
void insertAtEndOne(Node* head, Node* tail, int data) {
	tail=getTail(head, tail);
	
	insertAfter(tail,data);
}

void insertAtEndTwo(Node** head, int data) {
	Node* newNode=new Node(data);
	
	newNode->next=NULL;
	
	// If the list is empty...
	if((*head)==NULL){
		// Then this is the only
		// node in the list
		newNode->prev=NULL;
	}
	
	Node* tail=(*head);
	
	// Travel to the end of the list
	while(tail->next!=NULL) {
		tail=tail->next;
	}
	
	// Assign the new node after the tail
	tail->next=newNode;
	newNode->prev=tail;
		
}

void insertBefore(Node* current, int data) {
	// Edge case
	if(current==NULL) {
		cout<<"Error"<<endl;
		return;
	}
	
	// Create a new node with the given
	// data
	Node* newNode=new Node(data);
	newNode->prev=current->prev;
	current->prev=newNode;
	newNode->next=current;
	
	// If the node before the given one is not null...
	if(newNode->prev!=NULL) {
		// set next to that node to the new node
		newNode->prev->next=newNode;
	} else {
		// the new node is at the front
		// of the list.
		newNode->prev=NULL;
	}
	
}

void deleteGivenNode(Node** head, Node* givenNode) {
	// If the given node is the head
	if(givenNode==(*head)) {
		(*head)=givenNode->next;
	}
	
	givenNode->prev->next=givenNode->next;
	
	// Given node was the tail.
	// This if basically checks if the given node is the tail,
	// if it is, then the method is stopped here so that the
	// the attempt to acces a "prev" value of the NULL doesn't
	// occur.
	if(givenNode->next==NULL){
		return;
	}
	
	givenNode->next->prev=givenNode->prev;
	
}

void search(Node* head, int target) {
	Node* current=head;
	int index=1;
	
	while(current!=NULL) {
		if(current->data==target) {
			cout<<"Found the target at node: "<<index<<endl;
			return;
		}
		index++;
		current=current->next;
	}
	cout<<"Target not found"<<endl;
}

void reverse(Node** head) {
	Node* temp=NULL;
	Node* current=*head;
	
	// To reverse the list we just swap
	// the next and prev of all the nodes
	while(current!=NULL) {
		temp=current->prev;
		current->prev=current->next;
		current->next=temp;
		current=current->prev;
	}
	// Temp will only remain NULL after
	// the while if the list was
	// empty from the beginning
	if(temp!=NULL)
		*head=temp->prev;
	
}

int main() {
	
	// Pointer to the head
	Node* head=NULL;
	
	// Pointer to the tail
	Node* tail=NULL;
	
	// INSERTING NODES TO THE FRONT
	// head needs to be passed as a reference (&) so that
	// the original value gets modified.
	/*
	insertAtFront(&head, 4);
	insertAtFront(&head, 3);
	insertAtFront(&head, 2);
	insertAtFront(&head, 1);

	cout<<"List printed in a forward direction: "<<endl;
	printListForward(head);
	
	cout<<"\n\nList printed backwards: "<<endl;
	printListBackwards(head, tail);
	*/
	
	// INSERTING AFTER A GIVEN NODE
	// 1st node
	Node* first=new Node(12);
	first->prev=NULL;
	
	head=first;
	
	// 2nd node
	Node* second=new Node(15);
	second->prev=first;
	second->next=NULL;
	
	first->next=second;
	
	cout<<"Original list:"<<endl;
	printListForward(head);
	
	insertAfter(first, 1);
	cout<<"\n\nList after insertAfter:"<<endl;
	printListForward(head);
	
	// INSERTING AT THE END OF THE LIST (my method)
	insertAtEndOne(head,getTail(head, tail), 40);
	cout<<"\n\nList after inserting at the end (1st):"<<endl;
	printListForward(head);
	
	// INSERTING AT THE END OF THE LIST (scaler's method)
	insertAtEndTwo(&head, 35);
	cout<<"\n\nList after inserting at the end (2nd):"<<endl;
	printListForward(head);
	
	// INSERTING BEFORE A GIVEN NODE
	insertBefore(second, 100);
	cout<<"\n\nList after inserting before a given node:"<<endl;
	printListForward(head);
	
	// DELETING
	deleteGivenNode(&head, second);
	cout<<"\n\nList after deleting a given node:"<<endl;
	printListForward(head);
	
	// SEARCHING
	cout<<"\n\nSearch: "<<endl;
	search(head, 35);
	search(head, 12);
	
	// REVERSE
	reverse(&head);
	cout<<"\nnList: "<<endl;
	printListForward(head);

	
	return 0;
	
}
