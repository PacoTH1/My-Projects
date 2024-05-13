#include <iostream>

using namespace std;

class Queue {
	public: 
		// Attributes
		int* Array;
		int Front;
		int Back;
		int Size;
		
		// Constructors
		Queue(int size) {
			Array=new int[size];
			Front=-1;
			Back=-1;
			Size=size;
		}
		
		// Methods
		bool isEmpty();
		bool isFull();
		void enqueue(int value);
		int dequeue();
		void printQueue();
	
};

// Methods' implementations
bool Queue::isEmpty() {
	if(Front==-1)
		return true;
	else
		return false;
}

bool Queue::isFull() {
	if((Back+1)%Size==Front)
		return true;
	else
		return false;
}

void Queue::enqueue(int value) {
	if(isFull()) {
		cout<<"\nThe queue is full"<<endl;
		return;
	}else if(isEmpty()){
		Front=0;
		Back=0;
	}else{
		Back=(Back+1)%Size;
	}
	
	Array[Back]=value;		
}

int Queue::dequeue() {
	int dequeuedEl;
	if(isEmpty()){
		cout<<"\nThe queue is empty"<<endl;
		return -1;
	// The front and back are only ever equal when 
	// they are empty; this section gets executed when
	// the only remaining element gets dequeued.
	}else if(Front==Back){
		dequeuedEl=Array[Front];
		Front=-1;
		Back=-1;
	}else{
		dequeuedEl=Array[Front];
		Front=(Front+1)%Size;
	}
	return dequeuedEl;	

}

void Queue::printQueue() {
	if(isEmpty()) {
		cout<<"\nQueue is empty"<<endl;
	} else {
		for(int i=Front;i<Back+1;i++) {
		cout<<Array[i]<<" ";
	}
	cout<<"\n";
	}
}


int main() {
	Queue *q1=new Queue(4);
	q1->enqueue(10);
	q1->enqueue(9);
	q1->enqueue(8);
	q1->enqueue(7);
	
	cout<<"Queue after inserting a few elements:"<<endl;
	q1->printQueue();
	
	cout<<"\nDequeued element: "<<q1->dequeue();
	cout<<"\nQueue after dequeueing one element: "<<endl;
	q1->printQueue();
	
	q1->enqueue(100);
	
	if(q1->isFull()) {
		cout<<"\nThe queue is full"<<endl;
	} else {
		cout<<"\nThe queue is not full"<<endl;
	}
	
	q1->enqueue(1000);
	
	
}
