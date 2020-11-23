#include<iostream>
using namespace std;

bool filter(int a[],int no,int k){
	// a="abc" no=5 --o/p should be ac
	int i=0;
	int sum=0;
	while(no>0){
		(no&1)? sum+=a[i] :sum+=0;
		i++;
		no = no>>1;
	}
	if(sum==k){
		cout<<"Yes"<<endl;
		return true;
	}
	else{
		return false;
	}
}
void generateSubsets(int a[],int len,int sum){
	//Generate a range of numbers from 2^n -1
	int n = len;
	int range = (1<<n) -1;
	
	for(int i=0;i<=range;i++){
		bool res = filter(a,i,sum);
		if(res==true){
			break;
		}
	}
	cout<<"No"<<endl;
	
}

int main()
{
	int n,sum;
	cin>>n>>sum;
	
	int *arr = new int[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	generateSubsets(arr,n,sum);
}
