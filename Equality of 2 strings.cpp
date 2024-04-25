#include <iostream>
#include <string>

using namespace std;


bool StringEqual(string str1,string str2) {
	if (str1.length() != str2.length())
		return false;
		
	int N = str1.length();
	int i = 0;
	
	while (i<N && str1[i] == str2[i]) {
		i++;
	}
	return i == N;
	
}


int main() {
	string test1 = "Test";
	string test2 = "Test";
	
	cout<<"Are "<<test1<<" and "<<test2<<" equal?"<<endl;
	if(StringEqual(test1,test2))
		cout<<"Yes!";
	else
		cout<<"No!";
	
}
