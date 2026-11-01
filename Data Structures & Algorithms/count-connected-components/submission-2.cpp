class Solution {
public:
    void bfs_traversal(int edge, int& comp, unordered_map<int,int>& visited, const vector<vector<int>>& edges)
    {
        comp++;
        queue<int> q;
        q.push(edge);
        visited[edge] = 1;
        while(!q.empty())
        {
            int e = q.front();
            q.pop();
            for(int i=0; i<edges.size(); i++)
            {
                if(edges[i][0]==e && visited[edges[i][1]]==0)
                {
                    q.push(edges[i][1]);
                    visited[edges[i][1]]=1;
                }
                else if(edges[i][1]==e && visited[edges[i][0]]==0)
                {
                    q.push(edges[i][0]);
                    visited[edges[i][0]]=1;
                }
            }
        }
        return;
        
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        if(edges.size()==0)
        {
            return n;
        }
        int comp = 0;
        unordered_map<int,int> visited;
        for(int i=0; i<n; i++)
        {
            if(visited[i]==0)
            {
                bfs_traversal(i,comp,visited,edges);
            }
        }
        return comp;

    }
};
