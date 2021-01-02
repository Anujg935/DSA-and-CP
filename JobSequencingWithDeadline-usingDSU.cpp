#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class dsu{
    int *parent;
    public:
        dsu(int n){
            parent = new int[n+1];
            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
        }

        int find(int s){
            if(s==parent[s])
                return s;
            
            return parent[s] = find(parent[s]);
        }

        void unionMerge(int u, int v){
            parent[v] = u;
        }
};

bool compare(pair<int, int> x, pair<int, int> y){
    return x.first > y.first;
}

int findMaxDeadline(pair<int, int> *arr, int n){
    int ans = 0;

    for(int i=0; i<n; i++){
        ans = max(ans, arr[i].second);
    }

    return ans;
}
int finfJobSequencing(pair<int, int> *arr, int n){
    sort(arr, arr+n, compare);

    int maxDeadline = findMaxDeadline(arr, n);

    dsu d(n);

    int maxProfit = 0;

    for(int i=0;i<n;i++){
        int availableSlots = d.find(arr[i].second);

        if(availableSlots > 0){

            d.unionMerge(d.find(availableSlots-1), availableSlots);

            maxProfit += arr[i].first;
        }
    }

    return maxProfit;
}

//using DSU time complexity is : O(n)
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

    for(int i=0;i<n;i++){
        int p, d;
        cin >> p >> d;
        input[i] = make_pair(p, d);
    }

    cout << "Max profit is: " << finfJobSequencing(input, n) << endl;
}
