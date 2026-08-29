class Solution {
public:
    int maxDifference(string s) {
        int l = s.length();
        int i=0;
        int j = 0;
        unordered_map<char,int> mp;

        for(int i=0; i<l; i++)
        {
            mp[s[i]]++;
        }

        int min = INT_MAX;
        int max = INT_MIN;
        for(int i=0; i<l; i++)
        {
            if(mp[s[i]]%2==0)
            {
                if(mp[s[i]]<min)
                    min = mp[s[i]];
            }
            else
            {
                if(mp[s[i]]>max)
                    max = mp[s[i]];
            }
        }
        return max - min;
    }
};