//ith bit of number

#include<iostream>
using namespace std;

int getIthBit(int n,int i){
	return (n>>i)&1;
}

int setIthBit(int n,int i){
	int mask=1<<i;
	return n | mask;
}

//clear ith bit of no to 0 

int clrBit(int n,int i){
	int mask=~(1<<i);
	return n & mask;
}
int main()
{
	int n,i;
	cout<<"Enter number : ";
	cin>>n;
	cout<<"index of bit: ";
	cin>>i;
	
	
	cout<<i<<"th bit is "<<getIthBit(n,i)<<endl;
	
	cout<<"after setting "<<i<<"th bit of "<<n <<" ,number becomes :"<<setIthBit(n,i)<<endl;

	cout<<"after clearing "<<i<<"th bit of "<<n <<" ,number becomes :"<<clrBit(n,i)<<endl;
}
