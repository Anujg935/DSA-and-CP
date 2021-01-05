#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;

    while(t--){
        int n, k, x, y;
        cin >> n >> k >> x >> y;
        if(x==y){
            cout << n << " " << n << endl;
        }
        else{
            vector<pair<int, int>> v;
            if(x<y){
                v.push_back({x+n-y, n});                
                v.push_back({n, n-y+x});
                v.push_back({y-x, 0});
                v.push_back({0, y-x});
            }
            else{
                v.push_back({n, n-x+y});
                v.push_back({n+y-x, n});
                v.push_back({0, x-y});
                v.push_back({x-y, 0});
            }

            pair<int, int> res = v[(k-1)%4];
            
            cout << res.first << " " << res.second << endl;
        }
    }
}
