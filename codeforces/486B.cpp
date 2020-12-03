#include <iostream>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    int **arr = new int*[m];
    for(int i=0;i<m;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    int *row = new int[m];
    for(int i=0;i<m;i++){
        row[i] = 1;
    }

    int *col = new int[n]{1};
    for(int i=0;i<n;i++){
        col[i] = 1;
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 0){
                row[i] = 0;
                col[j] = 0;
            }
        }
    }
    bool flag = true;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 1){
                if(row[i] + col[j] < 1){
                    flag = false;
                    break; 
                }
            }
        }
    }
    
    if(!flag)
        cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout << (row[i] & col[j]) <<" ";
            }
            cout <<endl;
        }
    }
    return 0;
}
