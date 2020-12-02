#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n ;
    int *arr = new int[n];
    int countG[5] = {0};
    for(int i=0;i<n;i++){
        cin >> arr[i];
        countG[arr[i]]++;
    }
    sort(arr, arr + n);
    int cnt = 0;
    for(int i=n-1;i>=0;i--){
        if(countG[arr[i]]>0){
            if(arr[i] ==4 ){
                cnt++;
                countG[arr[i]]--;
            }
            else{
                if(countG[4-arr[i]] >=0){
                    countG[arr[i]]--;
                    countG[4-arr[i]]--;
                    cnt++;
                }
                else{
                    countG[arr[i]]--;
                }
            }
        }
        
    }

    cout << cnt <<endl;
}
