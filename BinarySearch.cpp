#include <iostream>
#include <cmath>

using namespace std;

int BinarySearch(int A[],int sizeArray,int target) {
	int IndexHigh = sizeArray-1;
	int IndexLow = 0;
	while(IndexLow <= IndexHigh) {
		int IndexMid = floor((IndexHigh+IndexLow)/2);
		
		if(A[IndexMid]==target)
			return IndexMid;
		else if(A[IndexMid]<target)
			IndexLow=IndexMid+1;
		else
			IndexHigh = IndexMid-1;
	}
	return -1;
}

int main() {
	int A[]={1,4,9,12,15,32};
	int arraySize=sizeof(A)/sizeof(int);
	
	cout<<"Posicion del valor buscado: "<<BinarySearch(A,arraySize,32)<<endl;
	
}
