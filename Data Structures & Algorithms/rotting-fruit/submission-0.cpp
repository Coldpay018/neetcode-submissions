class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;
        int min = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        while(!q.empty() && fresh > 0) {
            int level = q.size();

            while(level--) {
                auto [i,j] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if(x < 0 || x >= rows || y < 0 || y >= cols)
                        continue;

                    if(grid[x][y] != 1)
                        continue;

                    grid[x][y] = 2;
                    fresh--;
                    q.push({x,y});
                }
            }

            min++;
        }

        return fresh == 0 ? min : -1;
    }
};