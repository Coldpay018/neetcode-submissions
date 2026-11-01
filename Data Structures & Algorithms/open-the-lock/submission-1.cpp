class Solution {
public:
    int bfs_traversal(vector<string>& deadends, string target)
    {
        queue<string> q;
        unordered_map<string,int> visited;
        int level = 0;
        int curr_level_elements = 0;
        for(int i=0; i<deadends.size(); i++)
        {
            visited[deadends[i]]=1;
        }

        if(visited["0000"]==1)
            return -1;

        q.push("0000");
        curr_level_elements++;
        
        while(!q.empty())
        {
            string a = q.front();
            if(a==target)
            {
                return level;
            }
            q.pop();
            curr_level_elements--;
            for(int i=0; i<4; i++)
            {
                string b = a;
                if(a[i]=='9')
                {
                    b[i] = '8';
                    if(visited[b]!=1)
                    {
                        q.push(b);
                        visited[b] = 1;
                    }
                    b[i] = '0';
                    if(visited[b]!=1)
                    {
                        q.push(b);
                        visited[b] = 1;
                    }
                }
                else if(a[i]=='0')
                {
                    b[i] = '1';
                    if(visited[b]!=1)
                    {
                        q.push(b);
                        visited[b] = 1;
                    }
                    b[i] = '9';
                    if(visited[b]!=1)
                    {
                        q.push(b);
                        visited[b] = 1;
                    }
                }
                else 
                {
                    
                    b[i] = ((b[i]-'0') + 1)+'0';
                    if(visited[b]!=1)
                    {
                        q.push(b);
                        visited[b] = 1;
                    }
                    
                    b[i] = ((b[i]-'0') - 2)+'0';

                    if(visited[b]!=1)
                    {
                        q.push(b);
                        visited[b] = 1;
                    }
                    
                }
            }
            if(curr_level_elements==0)
            {
                curr_level_elements = q.size();
                if(curr_level_elements>0)
                    level++;
            }
        }
        return -1;
    }
    int openLock(vector<string>& deadends, string target) {
        return bfs_traversal(deadends, target);
    }
};