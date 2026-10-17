class Solution {
public:
    bool valid(int a, int b, const int m, const int n, const map<pair<int,int>,int>& visited, const vector<vector<int>>& heights, int c, int d)
    {
        if(a<0 || a>=m || b<0 || b>=n || visited.contains({a,b}) || heights[a][b]<heights[c][d])
            return false;
        return true;
    }
    vector<vector<int>> bfs_traversal(const vector<vector<int>>& heights, int m, int n)
    {
        vector<vector<unordered_set<char>>> temp(m, vector<unordered_set<char>>(n));
        map<pair<int,int>,int> visited;
        queue<pair<int,int>> q1;

        for(int i=0; i<m; i++)
        {
            q1.push({i,0});
            visited[{i,0}]=1;
        }
        for(int j=1; j<n; j++)
        {
            q1.push({0,j});
            visited[{0,j}]=1;
        }

        while(!q1.empty())
        {
            pair<int,int> a = q1.front();
            q1.pop();
            int b = a.first;
            int c = a.second;

            temp[b][c].insert('P');

            if(valid(b-1,c,m,n,visited,heights,b,c))
            {
                q1.push({b-1,c});
                visited[{b-1,c}]=1;
            }
            if(valid(b,c-1,m,n,visited,heights,b,c))
            {
                q1.push({b,c-1});
                visited[{b,c-1}]=1;
            }
            if(valid(b+1,c,m,n,visited,heights,b,c))
            {
                q1.push({b+1,c});
                visited[{b+1,c}]=1;
            }
            if(valid(b,c+1,m,n,visited,heights,b,c))
            {
                q1.push({b,c+1});
                visited[{b,c+1}]=1;
            }
        }
        visited.clear();

        for(int i=0; i<m; i++)
        {
            q1.push({i,n-1});
            visited[{i,n-1}]=1;
        }
        for(int j=0; j<n-1; j++)
        {
            q1.push({m-1,j});
            visited[{m-1,j}]=1;
        }

        while(!q1.empty())
        {
            pair<int,int> a = q1.front();
            q1.pop();
            int b = a.first;
            int c = a.second;

            temp[b][c].insert('A');

            if(valid(b-1,c,m,n,visited,heights,b,c))
            {
                q1.push({b-1,c});
                visited[{b-1,c}]=1;
            }
            if(valid(b,c-1,m,n,visited,heights,b,c))
            {
                q1.push({b,c-1});
                visited[{b,c-1}]=1;
            }
            if(valid(b+1,c,m,n,visited,heights,b,c))
            {
                q1.push({b+1,c});
                visited[{b+1,c}]=1;
            }
            if(valid(b,c+1,m,n,visited,heights,b,c))
            {
                q1.push({b,c+1});
                visited[{b,c+1}]=1;
            }
        }
        vector<vector<int>> ans;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(temp[i][j].size()==2)
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        return bfs_traversal(heights,m,n);

    }
};
