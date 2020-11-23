#include<iostream>
using namespace std;

void findUnique2(int *a,int n){
	
	int res =0;
	for(int i=0;i<n;i++){
		res = res^a[i];
	}
	//find rightmostset bit in res
	int i=0;
	int temp =res;
	
	while(temp>0){
		if(temp&1){
			break;
		}
		i++;
		temp = temp>>1;
	}
	int num1=0,num2;
	int mask =  1<<i;
	for(int i=0;i<n;i++){
		if(mask&a[i]){
			num1 = num1^a[i];
		}
	}
	num2= res ^num1;
	
	cout<<"Unique nos are :"<<num1<<","<<num2<<endl;
}

int main()
{
	int n;
	int a[] = {1,3,5,6,3,2,1,2};
	n = sizeof(a)/sizeof(int);
	findUnique2(a,n);
}
