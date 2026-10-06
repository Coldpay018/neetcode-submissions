class Solution {
public:
    void change_to_zero(vector<vector<int>>& grid, int i, int j, int& area)
    {
        if(i<0 || i>=grid.size())
            return;
        if(j<0 || j>=grid[0].size())
            return;
        if(grid[i][j]==0)
            return;
        grid[i][j] = 0;
        area++;
        change_to_zero(grid,i-1,j,area);
        change_to_zero(grid, i,j-1,area);
        change_to_zero(grid, i+1, j,area);
        change_to_zero(grid,i, j+1,area);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_a = 0;
        int area = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                area = 0;
                if(grid[i][j]==1)
                {
                    change_to_zero(grid,i,j,area);
                    max_a = max(max_a,area);
                }
            }
        }

        return max_a;
        
    }
};
