#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> x, pair<int, int> y){
    return x.first > y.first;
}
//Time complexity of this greedy algorithm is O(n^2)
int main() {

    //Sample input
    /*7
    5 2
    12 1
    15 3
    20 2
    25 4
    30 4
    35 3*/

    //correct o/p for this i/p is : 110
    int n;
    cin >> n;
    
    // first element is profit second is deadlines
    pair<int, int> *input = new pair<int, int>[n];

    int max_slot = -1;
    for(int i=0;i<n;i++){
        int p, d;
        cin >> p >> d;
        input[i] = make_pair(p, d);
        max_slot = max(max_slot, d);
    }

    sort(input, input+n, compare);

    int *slots = new int[max_slot];
    
    for(int i=0;i < max_slot;i++){
        slots[i] = -1;
    }
    int max_profit = 0;

    for(int i=0; i<n; i++){
        for(int j=input[i].second-1; j>=0; j--){
            if(slots[j] == -1){
                
                max_profit += input[i].first;
                slots[j] = i;
                break;
            }
        }
    }

    cout << "Max profit is: " << max_profit << endl;
}
