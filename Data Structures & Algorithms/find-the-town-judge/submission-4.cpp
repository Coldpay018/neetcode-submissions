class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> incoming;
        unordered_map<int,int> outgoing;

        for(int i=0; i<trust.size(); i++)
        {
            outgoing[trust[i][0]]++;
            incoming[trust[i][1]]++;
        }
        for(int i=1; i<=n; i++)
        {
            if(outgoing[i]==0 && incoming[i]==n-1)
                return i;
        }
        return -1;
    }
};