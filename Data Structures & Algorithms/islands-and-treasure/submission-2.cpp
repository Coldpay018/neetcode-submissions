class Solution {
public:

    void add_node(int i, int j, queue<pair<int,int>>& q, vector<vector<int>>& grid, int dist)
    {
        if(i<0 || i>=grid.size())
            return;
        if(j<0 || j>=grid[0].size())
            return;
        if(grid[i][j]<INT_MAX)
            return;
        grid[i][j] = dist;
        q.push({i,j});
        return;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }
        int dist = 0;

        while(!q.empty())
        {
            int current_size = q.size();
            for(int i=0; i<current_size; i++)
            {
                pair<int,int> a = q.front();
                q.pop();
                int b = a.first;
                int c = a.second;
                add_node(b+1,c,q,grid,dist+1);
                add_node(b,c+1,q,grid,dist+1);
                add_node(b-1,c,q,grid,dist+1);
                add_node(b,c-1,q,grid,dist+1);
            }
            dist++;
        }
        return;
    }
};
