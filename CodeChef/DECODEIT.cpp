#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        char *encodedString  = new char[n];
        for(int i=0;i<n;i++){
            cin >> encodedString[i];
        }
        int i = 0;
        while(i<n){
            int factor = 8;
            int integerNo = 0;
            int j;
            for(j=i;j<i+4;j++){
                if(encodedString[j] == '1'){
                    integerNo += factor;
                }
                factor /= 2;
            }
            i = j;
            cout << char('a' + integerNo);
        }
        cout << endl;
    }
}
