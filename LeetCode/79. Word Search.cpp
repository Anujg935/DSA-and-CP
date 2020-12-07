class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int wordIdx){
        if(i>=board.size() || j >= board[0].size() || i < 0 || j < 0)
            return false;
        if(board[i][j] != word[wordIdx])
            return false;
        
        if(wordIdx == word.size()-1)
            return true;
        
        char temp = word[wordIdx];
        
        board[i][j] = '#';
        
        if(dfs(board, i+1, j, word, wordIdx+1))
            return true;
                
        if(dfs(board, i, j+1, word, wordIdx+1))
            return true;
        
        if(dfs(board, i-1, j, word, wordIdx+1))
            return true;
        
        if(dfs(board, i, j-1, word, wordIdx+1))
            return true;
        
        board[i][j] = temp;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    bool ans = dfs(board, i, j, word, 0);
                    if(ans)
                        return ans;
                }
            }
        }
        return false;
    }
};