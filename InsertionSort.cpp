#include<iostream>

using namespace std;

void InsertionSort(int A[], int length) {
	int i=1;
	while(i<length) {
		int current = A[i];
		int j = i-1;
		while (j>=0&&A[j]>current) {
			A[j+1]=A[j];
			j = j-1;
		}
		A[j+1]=current;
		i++;
	}
}

int main() {
	int test1[] = {1,4,2,8,6,3};
	int arraySize = 6;
	
	cout << "Unsorted array:" << endl;
	cout << endl;
	
	for(int i = 0; i < arraySize; i++) {
	    cout << "A[" << i << "]" << " = " << test1[i] << endl;
	}
	
	InsertionSort(test1, 6);
	
	cout << "\nSorted array:" << endl;
	cout << endl;
	
	for(int i = 0; i < arraySize; i++) {
	    cout << "A[" << i << "]" << " = " << test1[i] << endl;
	}
	
	
}
