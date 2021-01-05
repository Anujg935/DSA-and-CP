#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;

    while(t--){
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> v(n, 0);
        int s = 0;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            v[i] = x;
            s += x;
        }

        if(s < k){
            cout << 0 << endl;
        }
        else{
            cout << min(s/k, d) << endl;
        }
    }
}
