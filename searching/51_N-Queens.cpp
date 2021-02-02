class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if(n == 0){
            return ans;
        }
        vector<string> board(n, string(n, '.'));
        vector<bool> column(n, false), ldig(2*n-1, false), rdig(2*n-1, false);
        backtracking(ans, board, column, ldig, rdig, 0, n);
        return ans;
    }

    void backtracking(vector<vector<string>>& ans, vector<string>& board, vector<bool>& column, vector<bool>& ldig, vector<bool>& rdig, int row, int n){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int i = 0; i < n; ++i){
            if(column[i] || ldig[n - row + i -1] || rdig[row + i + 1]){
                continue;
            }
            board[row][i] = 'Q';
            column[i] = ldig[n-row+i-1] = rdig[row+i+1] = true;
            backtracking(ans, board, column, ldig, rdig, row+1, n);
            board[row][i] = '.';
            column[i] = ldig[n-row+i-1] = rdig[row+i+1] = false;
        }
    }
};