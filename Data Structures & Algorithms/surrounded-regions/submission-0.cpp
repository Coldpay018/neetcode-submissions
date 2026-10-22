class Solution {
public:
    void bfs_traversal(vector<vector<char>>& board)
    {
        queue<pair<int,int>> coords;
 
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n,0));

        for(int i=0; i<m; i++)
        {
            if(board[i][0]=='O')
            {
                coords.push({i,0});
                visited[i][0] = 1;
            }
            if(board[i][n-1]=='O')
            {
                coords.push({i,n-1});
                visited[i][n-1]=1;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(board[0][i]=='O')
            {
                coords.push({0,i});
                visited[0][i] = 1;
            }
            if(board[m-1][i]=='O')
            {
                coords.push({m-1,i});
                visited[m-1][i] = 1;
            }
        }

        while(!coords.empty())
        {
            pair<int,int> a = coords.front();
            coords.pop();
            int r = a.first;
            int c = a.second;

            board[r][c] = '.';

            if(r>0 && visited[r-1][c]==0 && board[r-1][c]=='O')
            {
                coords.push({r-1,c});
                visited[r-1][c] = 1;
            }
            if(c>0 && visited[r][c-1]==0 && board[r][c-1]=='O')
            {
                coords.push({r,c-1});
                visited[r][c-1] = 1;
            }
            if(r<m-1 && visited[r+1][c]==0 && board[r+1][c]=='O')
            {
                coords.push({r+1,c});
                visited[r+1][c] = 1;
            }
            if(c<n-1 && visited[r][c+1]==0 && board[r][c+1]=='O')
            {
                coords.push({r,c+1});
                visited[r][c+1] = 1;
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
