#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
pair<ll, ll> lower_bound(ll *arr, ll n, ll target){
    ll l = 0, r = n-1;
    ll lower;
    while(l<=r){
        ll mid = (l+r)/2;
        if(arr[mid] == target){
            r = mid -1;
        }
        else if(arr[mid] < target){
            lower = mid;
            l = mid +1;
        }
        else{
            r = mid -1;
        }
    }

    return make_pair(arr[lower], lower);
}
void solve(ll *rooms_size, ll n, ll *letters, ll m){
    for(int i=0;i<m;i++){
        pair<ll, ll> l = lower_bound(rooms_size, n, letters[i]);
        cout << l.second+1 <<" " << letters[i] - l.first <<endl; 
    }
}
int main() {
    ll n_dormatries, letters;
    cin >> n_dormatries >> letters;

    ll *rooms_size = new ll[n_dormatries+1];
    rooms_size[0] = 0;
    for(int i=1;i<=n_dormatries;i++){
        cin >> rooms_size[i];

        rooms_size[i] += rooms_size[i-1] ;
    }

    
    
    ll *room_number = new ll[letters];
    for(int i=0;i<=letters;i++){
        cin >> room_number[i];
    }
    solve(rooms_size, n_dormatries+1, room_number, letters);
}
