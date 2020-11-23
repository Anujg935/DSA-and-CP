//XOR Swapping

#include<iostream>
using namespace std;

int main()
{
	int a,b;
	cout<<"Enter a: ";
	cin>>a;
	
	cout<<"Enter b: ";
	cin>>b;
	
	a=a^b;
	b=b^a;
	a=a^b;
	
	cout<<"a is :"<<a<<endl;
	cout<<"b is :"<<b<<endl;
}
