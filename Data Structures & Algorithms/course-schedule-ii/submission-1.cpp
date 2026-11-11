class Solution {
public:
    vector<int> bfs_traversal(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> visited;
        vector<vector<int>> adj(numCourses);
        vector<int> remaining(numCourses);
        for(int i=0; i<prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            remaining[prerequisites[i][0]]++;
        } 
        
        queue<int> q;
        for(int i=0; i<remaining.size(); i++)
        {
            if(remaining[i]==0)
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


            for(int i=0; i<adj[a].size(); i++)
            {
                remaining[adj[a][i]]--;
                if(remaining[adj[a][i]]==0)
                {
                    visited.push_back(adj[a][i]);
                    q.push(adj[a][i]);
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
