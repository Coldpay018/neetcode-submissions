class Solution {
public:
    int valid(pair<int,int> a, const vector<vector<int>>& grid, const map<pair<int,int>,int>& visited)
    {
        if(a.first<0 || a.first>=grid.size())
            return 0;
        if(a.second<0 || a.second>=grid[0].size())
            return 0;
        if(grid[a.first][a.second]!=1 || visited.count(a)>0)
            return 0;
        return 1;
    }

    int multi_source_bfs(vector<vector<int>>& grid)
    {
        map<pair<int,int>,int> visited;
        queue<pair<int,int>> q;

        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    visited[{i,j}]=1;
                }
            }
        }

        int level = q.size();
        int time = 0;

        while(!q.empty())
        {
            pair<int,int> a = q.front();
            q.pop();

            level--;

            int b = a.first;
            int c = a.second;
            grid[b][c] = 2;

            if(valid({b-1,c},grid,visited))
            {
                q.push({b-1,c});
                visited[{b-1,c}]=1;
            }

            if(valid({b,c-1},grid,visited))
            {
                q.push({b,c-1});
                visited[{b,c-1}]=1;
            }

            if(valid({b+1,c},grid,visited))
            {
                q.push({b+1,c});
                visited[{b+1,c}]=1;
            }

            if(valid({b,c+1},grid,visited))
            {
                q.push({b,c+1});
                visited[{b,c+1}]=1;
            }
            
            if(level==0)
            {
                if(q.size()!=0)
                {
                    time++;
                    level = q.size();
                }
                else
                    break;
            }
        }
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        return multi_source_bfs(grid);
    }
};
