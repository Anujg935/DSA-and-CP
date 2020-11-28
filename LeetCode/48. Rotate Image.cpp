class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int n = matrix.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && i>j){
                    int t = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = t;
                }
            }
        }
    
        int i=0,j=n-1;

        while(i<j){
            for(int k=0;k<n;k++){
                int t = matrix[k][i];
                matrix[k][i] = matrix[k][j];
                matrix[k][j] = t;
            }
            i++;j--;
        }
    }
};