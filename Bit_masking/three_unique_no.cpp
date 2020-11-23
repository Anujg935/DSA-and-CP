#include<iostream>
using namespace std;


int findUniquethree(int a[],int n){
	int cnt[64] = {0};
	
	for(int j=0;j<n;j++){
		int i = 0;
		int no = a[j];
		
		while(no>0){
			cnt[i] += no&1;
			i++;
			no = no >>1;
		}
	}
	int p = 1;
	int ans=0;
	for(int i=0;i<64;i++){
		cnt[i] = cnt[i] %3;
		
		ans += cnt[i]*p;
		p = p <<1;
	}
	
	return ans;
	
}
int main()
{
	int arr[] = {7,7,3,4,2,3,3,4,4,6,6,7,6};
	
	cout<< findUniquethree(arr,sizeof(arr)/sizeof(int))<<endl;
}
