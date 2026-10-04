class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int col = grid[0].size();

        int p = 0;

        int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j]==0)
                    continue;
                
                for(auto& dir: directions)
                {
                    int nr = i + dir[0];
                    int nc = j + dir[1];

                    if(nr<0 || nr>=grid.size() || nc<0 || nc>=grid[0].size() || grid[nr][nc]==0)
                        p++;
                }
            }
        }
        return p;
    }
};