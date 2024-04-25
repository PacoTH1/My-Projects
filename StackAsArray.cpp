#include <iostream>

using namespace std;

class Stack {
	public: 
	int arraySize;
	int top;
	int* array;
		
	Stack(int size) {
		arraySize=size;
		top=-1;
		array=new int[arraySize];
	}
	
	void push(int value);
	int pop();
	
	
};

// Method to double the size of an array
int* doubleArray(const int* oldArray,int oldLength) {
	// The array has to be static so that it can work
	// outside of this function.
	int* newArray=new int[oldLength*2];
	int j=0;
	while(j<oldLength) {
		newArray[j]=oldArray[j];
		j++;
	}
	return newArray;	
		
}

void Stack::push(int value) {
	// If the stack is full...
	if(top==arraySize-1) {
		array=doubleArray(array, arraySize);
		arraySize*=2;
	}
	top=top+1;
	array[top]=value;
}

int Stack::pop() {
	int value;
	if(top>-1) {
		value=array[top];
		top--;
		return value;
	} else {
		cout<<"Error-The stack is empty"<<endl;
		return -1;
	}
}

void printStack(Stack s) {
	for(int i=s.top;i>=0;i--) {
		cout<<s.array[i]<<endl;
	}
}

int main() {
	//Stack* stack1=new Stack(3);
	// STACK 1
	// PUSH
	Stack stack1(3);
	/*
	stack1.push(10);
	stack1.push(20);
	stack1.push(30);
	
	printStack(stack1);
	
	// POP
	int poppedEl=stack1.pop();
	cout<<"\n\nPopped element: "<<poppedEl<<endl;
	printStack(stack1);
	
	// Verifying the doubling
	stack1.push(2);
	cout<<"\n\nSize of the array: "<<stack1.arraySize<<endl;
	printStack(stack1);
	stack1.push(40);
	cout<<"\n\nSize of the array after adding something while it's at its limit: "<<stack1.arraySize<<endl;
	printStack(stack1);*/
	
	int test=stack1.pop();
	cout<<"\n\nValue: "<<test<<endl;
	
	
	
}
