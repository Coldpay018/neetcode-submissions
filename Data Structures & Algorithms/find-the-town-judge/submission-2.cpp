class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> mp;
        for(int i=1; i<=n; i++)
        {
            mp[i]=0;
        }

        for(auto& a : trust)
        {
            if(mp[a[0]]!=-1)
                mp[a[0]]=-1;
            if(mp[a[1]]!=-1)
                mp[a[1]]++;
        }
        for(int i=0; i<mp.size(); i++)
        {
            if(mp[i]==n-1)
                return i;
        }
        return -1;

        
    }
};