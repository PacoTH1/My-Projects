#include <iostream>

using namespace std;

// Para arreglos de tamaño fijo o dinamico
int LinearScan(int A[],int arraySize,int target){
	int i = 0;
	while(i<arraySize){
		if(A[i]==target)
			return i;
		i++;
	}
	return -1;
}

// Para arreglos de tamaño dinamico
// Este no funciona, ya que usar el sizeof en una funcion
// solo obtiene el primer valor del arreglo, asi que el
// tamaño que obtiene es 1
int LinearScanTwo(int A[],int target){
	int i = 0;
	while(i<(sizeof(A)/sizeof(A[0]))){
		if(A[i]==target)
			return i;
		i++;
	}
	return -1;
}



int main() {
	int A[]={4,2,21,8,10};
	
	int indice = LinearScan(A,5,10);
	int indice2 = LinearScanTwo(A,10);
	
	cout<<"A\n\nIndice: "<<indice<<endl;
	cout<<"\nIndice2: "<<indice2<<endl;
	
	int B[]={12,23,10,1,4,8};
	int arraySize = sizeof(B)/sizeof(int);
	int indice3 = LinearScan(B,arraySize,1);
	cout<<"\nB\n\nIndice: "<<indice3<<endl;	

}
