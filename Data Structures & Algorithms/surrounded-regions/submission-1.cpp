class Solution {
public:
    void bfs_traversal(vector<vector<char>>& board)
    {
        queue<pair<int,int>> coords;
 
        int m = board.size();
        int n = board[0].size();

        for(int i=1; i<m-1; i++)
        {
            if(board[i][0]=='O')
            {
                coords.push({i,0});
            }
            if(board[i][n-1]=='O')
            {
                coords.push({i,n-1});
            }
        }
        for(int i=0; i<n; i++)
        {
            if(board[0][i]=='O')
            {
                coords.push({0,i});
            }
            if(board[m-1][i]=='O')
            {
                coords.push({m-1,i});
            }
        }

        while(!coords.empty())
        {
            pair<int,int> a = coords.front();
            coords.pop();
            int r = a.first;
            int c = a.second;

            board[r][c] = '.';

            if(r>0 && board[r-1][c]=='O')
            {
                coords.push({r-1,c});
            }
            if(c>0 && board[r][c-1]=='O')
            {
                coords.push({r,c-1});
            }
            if(r<m-1 && board[r+1][c]=='O')
            {
                coords.push({r+1,c});
            }
            if(c<n-1 && board[r][c+1]=='O')
            {
                coords.push({r,c+1});
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(board[i][j]=='O')
                    board[i][j] = 'X';
                else if(board[i][j]=='.')
                    board[i][j] = 'O';
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        return bfs_traversal(board);
        
    }
};
