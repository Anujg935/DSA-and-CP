#include<iostream>

//calculate how many bit required to change one number to another

using namespace std;

// Time O(no of bits)
int countBits(int n){
	int count=0;
	
	while(n>0){
		count+= n&1;
		n = n>>1; //right shift
	}
	return count;
}

//Time o(no of set bits)

int countBitsFast(int n){
	int count=0;
	
	while(n>0){
		count+=1;
		n = n&(n-1); //adnding with n-1 removes last set bit
	}
	return count;
}
int main()
{
	int a,b;
	cin>>a>>b;
	
	int aXORb = a^b;
	
	cout<<"No of bits required to change from "<<a<<" to "<<b<<" is :"<< countBits(aXORb)<<endl;
	
	cout<<"No of bits required to change from "<<a<<" to "<<b<<" is :"<< countBitsFast(aXORb)<<endl;
}

