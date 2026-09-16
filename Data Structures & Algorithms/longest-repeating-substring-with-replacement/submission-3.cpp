class Solution {
public:
    int check(vector<int>& freq, string& s, int l, int r)
    {
        int max_char = 0;
        for(int i=0; i<26; i++)
        {
            if(freq[i]>max_char)
                max_char = freq[i];
        }
        return max_char;
    }
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int max_len = 0;
        int flag=1;
        vector<int> freq(26);
        while(r<s.length())
        {
            if(flag==1)
                freq[s[r]-'A']++;
            int max_count = check(freq, s, l, r);
            if(r-l+1 - max_count <=k)
            {
                max_len = max(max_len, r-l+1);
                r++;
                flag=1;
            }
            else
            {
                freq[s[l]-'A']--;
                l++;
                flag=0;
            }
        }
        return max_len;

    }
};
