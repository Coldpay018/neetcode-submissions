class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()<n-1)
            return -1;
        
        vector<int> potential;

        for(int i=1; i<=n; i++)
        {
            int flag = 1;
            for(vector<int> j : trust)
            {
                if(j[0]==i)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag!=0)
                potential.push_back(i);
        }

        for(int i=0; i<potential.size(); i++)
        {
            int count = 0;
            for(int j=0; j<trust.size(); j++)
            {
                if(trust[j][1]==potential[i])
                    count++;
            }
            if(count==n-1)
                return potential[i];
        }
        return -1;
        
    }
};