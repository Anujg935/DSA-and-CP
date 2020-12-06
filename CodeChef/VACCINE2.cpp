#include <iostream>
#include <cmath> 
using namespace std;
int main() {
    int t = 0;
    cin >> t;

    while(t--){
        int n, d;
        cin >> n >> d;
        
        int cntRisky = 0;
        int cntNonRisky = 0;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            if(x <=9 || x>=80)
                cntRisky++;
            else
                cntNonRisky++;
        }
        int a = ceil((double)cntNonRisky/d);
        int b = ceil((double)cntRisky/d);
        
        cout << a + b <<endl;
    }
}
