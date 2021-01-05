class Solution {
public:
    bool canPlace(vector<vector<char>>& board, int n, int row, int col, int currNum){
        
        for(int i=0;i<n;i++){
            if(board[row][i] == '0' + currNum) return false;
            if(board[i][col] == '0' + currNum) return false;
        }
        
        int sqrtn = 3;
        
        int boxRow = row/sqrtn;
        int boxCol = col/sqrtn;
        
        int RowCell = boxRow * sqrtn;
        int ColCell = boxCol * sqrtn;
        
        for(int i=RowCell;i<RowCell+sqrtn;i++){
            for(int j= ColCell;j<ColCell+sqrtn;j++){
                if(board[i][j] == '0' +currNum) return false;
            }
        }
        
        return true;
    }
    bool sudokuSolver(vector<vector<char>>& board, int n, int row, int col){
        if(row==n){
            return true;
        }
        if(col==n){
            return sudokuSolver(board, n, row+1, 0);
        }
        
        if(board[row][col]!='.'){
            return sudokuSolver(board, n, row, col+1);
        }
        
        
        for(int currNum=1;currNum<=n;currNum++){
            if(canPlace(board, n, row, col, currNum)){
                board[row][col] = '0' + currNum;
                bool success = sudokuSolver(board, n, row, col+1);
                
                if(success) return true;
                
                board[row][col] = '.';
            }
        }
        
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        sudokuSolver(board, 9, 0, 0);
    }
};