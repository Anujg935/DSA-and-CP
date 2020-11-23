#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void LongestConsecutiveSeq(int *arr, int n){
    pair<int, int> *dp = new pair<int, int>[n];
    for(int i=0;i<n;i++){
        dp[i] = make_pair(1,-1);
    }
    int ans = 1;
    int Lastindex = 0 ;
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j] +1 == arr[i]){
                dp[i].first += dp[j].first;
                dp[i].second = j;  
                
                if(dp[i].first>= ans){
                    ans = dp[i].first;
                    Lastindex = i;
                }
                break;
            }
        }
    }
    cout << ans <<endl;
    vector<int> res;
    while(dp[Lastindex].second !=-1){
        //cout << Lastindex+1<<" ";
        res.insert(res.begin(), Lastindex+1);
        Lastindex = dp[Lastindex].second;
    }
    res.insert(res.begin(), Lastindex+1);

    for(auto i: res){
        cout << i <<" ";
    }
}
int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
      
    LongestConsecutiveSeq(arr, n);
}
