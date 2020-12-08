class Solution {
public:
    
    int dfs(vector<vector<char>>& grid, int i, int j){
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0){
            return 0;
        }
        
        if(grid[i][j] != '1')
            return 0;
        
        grid[i][j] = '#';
        int ans = 1;
        
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size();j++){
                if(grid[i][j] == '1'){
                    ans +=dfs(grid, i, j);
                }
            }
        }
        
        return ans;
    }
};