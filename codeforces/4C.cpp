//https://codeforces.com/problemset/problem/4/C

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    unordered_map<string, int> um;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if(um.count(s)){
            int cnt = um[s];
            um[s]++;
            cout << s << cnt << endl;
        }
        else{
            um[s] = 1;
            cout << "OK" <<endl;
        }
    }
}
