#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string maximalTwogram(string str, int n){
    map<string, int> mCount;

    for(int i=0;i<n-1;i++){
            if(mCount.count(str.substr(i, 2))){
                mCount[str.substr(i, 2)] += 1;
            }
            else{
                mCount[str.substr(i, 2)] = 1;
            }
    }
    string resString ;
    int m = 0;
    for(auto i:mCount){
        if(i.second > m){
            resString = i.first;
            m = i.second;
        }
    }

    return resString;
}
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    cout << maximalTwogram(s, n) <<endl;
}
