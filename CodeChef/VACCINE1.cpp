#include <iostream>
using namespace std;
int main() {
    int d1, v1, d2, v2, p;

    cin >> d1 >> v1 >> d2 >> v2 >> p;

    if(p==0){
        cout << 0 << endl;
        return 0;
    }

    if(d1 > d2){
        int temp = d1, temp2  = v1;
        d1 = d2;v1 = v2;
        d2 = temp;v2 = temp2;
    }
    int produced = 0;
    int days = d1 - 1;
    for(int i = d1; i<d2; i++){
        produced += v1;
        days++;
        if(produced >= p){
            cout << days << endl; 
            return 0;
        }
    }
    while(produced < p){
        produced += (v1 +v2);
        days++;
    }
    
    cout << days << endl; 
        
}
