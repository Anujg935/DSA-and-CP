class Solution {
public:
    bool isSafe(char **board, int n, int row, int col){

        for(int i=0;i<row;i++){
            if(board[i][col] == 'Q')
                return false;
        }

        for(int i=0;i<col;i++){
            if(board[row][i] == 'Q')
                return false;
        }
        //upper diagnol on left side
        for(int i=row, j=col; i>=0 && j>=0; i--,j--){
            if(board[i][j] == 'Q')
                return false;
        }

        //Lower diagnol on left side
        for(int i=row, j=col; i<n && j>=0; i++,j--){
            if(board[i][j] == 'Q')
                return false;
        }

        return true;
    }
    vector<vector<string>> res;
    void nqueen(char **board, int n, int col){
        if(col==n){
            //printBoard(board, n);
            vector<string> v;
            for(int i=0;i<n;i++){
                string s ="";
                for(int j=0;j<n;j++){
                    s = s + board[i][j];
                }
                v.push_back(s);
            }
            res.push_back(v);
            return;
        }

        for(int i=0; i<n; i++){
            if(isSafe(board, n, i, col)){
                board[i][col] = 'Q';

                nqueen(board, n, col+1);

                board[i][col] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        char **board = new char*[n];
        for(int i=0;i<n;i++){
            board[i] = new char[n];
            for(int j=0;j<n;j++){
                board[i][j] = '.';
            }
        }

        nqueen(board, n, 0);
        return res;
    }
};#include <iostream>
using namespace std;
int main() {
    cout<<"Hello World!";
}
