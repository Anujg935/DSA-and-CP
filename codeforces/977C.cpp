#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    if(k==0){
        if(arr[0]-1 >=1)
            cout << arr[0] -1<<endl;
        else
            cout << -1 <<endl;
        return 0;
    }
    int t = arr[k-1];
    if(t+1 < arr[k]){
        cout << t+1<<endl;
    }
    else{
        cout << -1 <<endl;
    }
}
