class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row==0)
            return false;
        
        int col = matrix[0].size();
        
        int i = 0;
        int j = col -1;
        
        while((i>=0 && j>=0) && (i<row && j< col)){
            if(matrix[i][j] == target)
                return true;
            else if(target < matrix[i][j])
                j--;
            else if(target > matrix[i][j])
                i++;
            else
                return false;
        }
        return false;
    }
};