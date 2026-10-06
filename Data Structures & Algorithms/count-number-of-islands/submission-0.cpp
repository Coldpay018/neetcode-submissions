class Solution {
public:
    void change_to_zero(vector<vector<char>>& grid, int i, int j)
    {
        if(i<0 || i>=grid.size())
            return;
        if(j<0 || j>=grid[0].size())
            return;
        if(grid[i][j]=='0')
            return;
        grid[i][j] = '0';
        change_to_zero(grid,i-1,j);
        change_to_zero(grid, i,j-1);
        change_to_zero(grid, i+1, j);
        change_to_zero(grid,i, j+1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    change_to_zero(grid,i,j);
                }
            }
        }
        return count;
    }
};
