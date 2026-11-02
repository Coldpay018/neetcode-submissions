class Solution {
public:
    bool bfs_traversal(unordered_map<int,int>& visited, const vector<vector<int>>& adj, int edge)
    {
        queue<pair<int,int>> q;
        q.push({edge,-1});
        visited[edge]=1;
        while(!q.empty())
        {
            pair<int, int> a = q.front();
            q.pop();
            for(int i=0; i<adj[a.first].size(); i++)
            {
                if(visited[adj[a.first][i]]==1 && adj[a.first][i]!=a.second)
                    return false;
                if(visited[adj[a.first][i]]==0)
                {
                    q.push({adj[a.first][i],a.first});
                    visited[adj[a.first][i]]=1;
                }  
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_map<int,int> visited;
        int count = 0;
        for(int i=0; i<n; i++)
        {
            if(visited[i]==0)
            {
                count++;
                if(count==2)
                    return false;
                if(bfs_traversal(visited, adj, i)==false)
                    return false;
                else
                    continue;
            }
        }
        return true;

    }
};
