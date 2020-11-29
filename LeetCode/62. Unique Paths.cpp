class Solution {
public:
    int uniquePaths(int m, int n) {
        // Mathematical Solution efficient
        // In this method we are using observation
        //that in m*n grid we are taking m-1 down steps and n-1 right steps
        // total n+m-2 steps and to find unique paths we nee to find either of 
        // (n+m-2)^C(n-1) or (n+m-2)^C(m-1) 
        int N = n+m-2;
        int r = m-1;
        double res = 1;
        
        
        for(int i=1;i<=r;i++){
            res = res*(N-r+i)/i;
        }
        
        return (int)res;
        
        
        //DP Solution
        /*int **arr = new int*[m];
        for(int i=0;i<m;i++){
            arr[i] = new int [n];
            for(int j=0;j<n;j++){
                arr[i][j] = 0;
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0)
                    arr[i][j] = 1;
                else
                    arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }
        
        return arr[m-1][n-1];*/
    }
};