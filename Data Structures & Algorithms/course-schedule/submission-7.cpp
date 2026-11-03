class Solution {
public:
    bool bfs_traversal(vector<vector<int>>& adj, int numCourses)
    {
        queue<int> q;
        unordered_map<int,int> visited;
        int counter = 0;
        for(int i=0; i<adj.size(); i++)
        {
            if(adj[i].empty())
            {
                q.push(i);
                visited[i]=1;
                adj[i].push_back(-1);
                counter++;
            }
        }
        while(!q.empty())
        {
            int a = q.front();
            q.pop();
            for(int i=0; i<adj.size(); i++)
            {
                if(find(adj[i].begin(), adj[i].end(), a)!=adj[i].end())
                {
                    adj[i].erase(find(adj[i].begin(), adj[i].end(),a));
                    if(adj[i].empty() && visited[i]==0)
                    {
                        q.push(i);
                        visited[i]=1;
                        counter++;
                    }
                }
            }
            if(counter>=numCourses)
                return true;
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(int i=0; i<prerequisites.size(); i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        return bfs_traversal(adj,numCourses);

    }
};
