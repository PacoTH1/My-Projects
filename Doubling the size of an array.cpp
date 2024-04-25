#include <iostream>

using namespace std;

// An array cannot be returned directly.
// What can be returned is a pointer to an array.
int* arrayDouble(const int* oldArray,int oldLength) {
	int* newArray=new int[oldLength*2];
	int j=0;
	while(j<oldLength) {
		newArray[j]=oldArray[j];
		j++;
	}
	return newArray;	
		
}

int main() {
	int test1[] = {3,4,5,6};
	int oldSize = sizeof(test1)/sizeof(int); 
	cout<<"Original array"<<endl;
	for(int i=0;i<oldSize;i++) {
		cout<<"test1["<<i<<"] = "<<test1[i]<<endl;	
	}
	
	// The method can take an array because when an 
	// array is passed to a function, it decays into
	// a pointer to its first element.
	int* doubledArray = arrayDouble(test1,oldSize);
	int newSize = oldSize*2;
	cout<<"\nNewArray"<<endl;
	for(int i=0;i<newSize;i++) {
		cout<<"doubledArray["<<i<<"] = "<<doubledArray[i]<<endl;	
	}
	cout<<"New size = "<<newSize;
	
	delete[] doubledArray; // Free dynamically allocated memory

	return 0;
	
}
