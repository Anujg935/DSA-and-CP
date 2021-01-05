#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b){
    return a>b;
}

int main() {
    int t;
    cin >> t;

    while(t--){
        int n1, n2;
        cin >> n1 >> n2;

        int *arr1 = new int[n1];
        int *arr2 = new int[n2];
        int s1 = 0;
        int s2 = 0;
        for(int i=0;i<n1;i++){
            cin >> arr1[i];
            s1 += arr1[i];
        }

        for(int i=0;i<n2;i++){
            cin >> arr2[i];
            s2 += arr2[i];
        }

        sort(arr1, arr1 + n1);
        sort(arr2, arr2 + n2, compare);
        int swaps = 0;
        if(s1>s2){
            cout << 0 << endl;
        }
        else{
            for(int i=0, j = 0;i<n1 && j<n2;i++, j++){
                int a = arr1[i];
                int b = arr2[j];
                s1 = s1 + b - a;
                s2 = s2 - b + a;
                swaps++;
                if(s1>s2){
                    break;
                }
            }

            if(s1 > s2){
                cout << swaps << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
        

    }
}
