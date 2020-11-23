#include<iostream>

using namespace std;

int computeNoBits(int n){
	int count=0;
	while(n>0){
		count+=1;
		n = n&(n-1);
	}
	return count;
}
int main()
{
	int arr[3] ={3,4,5};
	
	for(int i=0;i<3;i++){
		cout<<"Min no of steps needed by hulk for "<<arr[i]<<"steps is : " <<computeNoBits(arr[i])<<endl;
	} 
}
