class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> vec(256,-1);

        int l = 0;
        int r = 0;
        int max_length = INT_MIN;
        while(r<n)
        {
            if(vec[s[r]]>=l)
            {
                l = vec[s[r]] + 1;
            }
            vec[s[r]] = r;
            max_length = max(max_length, r-l+1);
            r++;
        }
        return max(0,max_length);
        
    }
};
