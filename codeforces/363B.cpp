#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int *arr = new int [n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int sumTok = 0;
    for(int i=0;i<k;i++){
        sumTok += arr[i];
    }
    int minIdx = 0;
    int min_kh = INT_MAX;
    int last = arr[0];
    min_kh = min(min_kh, sumTok);
    for(int i=k;i<n;i++){
        sumTok = sumTok - arr[i-k] +arr[i];
        if(sumTok < min_kh){
            minIdx = i-k+1;
            min_kh = sumTok;
        }
    }

    cout << minIdx+1 <<endl;

}
