class Solution {
public:
    vector<int> bfs_traversal(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> visited;
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        } 
        
        queue<int> q;
        for(int i=0; i<adj.size(); i++)
        {
            if(adj[i].empty())
            {
                q.push(i);
                visited.push_back(i);
            }
        }
        if(visited.size()==numCourses)
            return visited;
        
        while(!q.empty())
        {
            int a = q.front();
            q.pop();
            for(int i=0; i<adj.size(); i++)
            {
                if(find(adj[i].begin(), adj[i].end(),a) != adj[i].end())
                {
                    erase(adj[i],a);
                    if(adj[i].size()==0)
                    {
                        visited.push_back(i);
                        q.push(i);
                        adj[i].push_back(-1);
                    }
                }
            }
            if(visited.size()==numCourses)
                return visited;
        }
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        return bfs_traversal(numCourses, prerequisites);
        
    }
};
