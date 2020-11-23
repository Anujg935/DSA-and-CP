#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int b=1;
	
	int res = n & b;
	
	if(res==1){
		cout<<"No is odd"<<endl;
	}
	else{
		cout<<"No is even"<<endl;
	}
}
