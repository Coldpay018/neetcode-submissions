class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> v(n+1,0);

        for(auto& a : trust)
        {
            if(v[a[0]]!=-1)
                v[a[0]]=-1;
            if(v[a[1]]!=-1)
                v[a[1]]++;
        }
        for(int i=1; i<v.size(); i++)
        {
            if(v[i]==n-1)
                return i;
        }
        return -1;

        
    }
};