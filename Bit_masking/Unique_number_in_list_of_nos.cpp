#include<iostream>

using namespace std;

int main(){
	
	// array with unique element 9
	int arr[13] = {1,2,1,3,2,3,9,5,5,6,6,8,8};
	
	// XOR ing all the elements will give the unique element
	int unique = arr[0]^arr[1];
	for(int i=2;i<sizeof(arr)/sizeof(int);i++){
		unique ^=arr[i];
	}
	
	cout<<"unique element in the list  is : "<<unique<<endl;
	
	return 0;
}
