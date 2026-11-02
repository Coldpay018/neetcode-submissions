class Solution {
public:
    bool safe(const vector<string>& board, int row, int col, int n)
    {
        int dup_row = row;
        int dup_col = col;

        while(col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            col--;
        }
        col = dup_col;

        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        row = dup_row;
        col = dup_col;
        while(row<n && col >=0)
        {
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    void backtracking(vector<vector<string>>& ans,vector<string>& board,int n, int c)
    {
            for(int row=0; row<n; row++)
            {
                if(safe(board,row,c,n))
                {
                    board[row][c] = 'Q';
                    if(c==n-1)
                    {
                        ans.push_back(board);
                    }
                    else
                    {
                        backtracking(ans,board,n,c+1);
                    }
                    board[row][c]='.';
                }
            }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        backtracking(ans,board,n,0);
        return ans;
        
        
    }
};
