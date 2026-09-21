class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty())
            return  "";
        
        unordered_map<char, int> countT;
        unordered_map<char,int> window;

        for(char c:t)
            countT[c]++;
        
        int have = 0;
        int need = countT.size();

        int l = 0;

        int start = -1;
        int resLen = INT_MAX;

        for(int r=0; r<s.size(); r++)
        {
            char c = s[r];
            
            if(countT.contains(c))
                window[c]++;
            else
                continue;

            if(window[c] == countT[c])
                have++;
            
            while(have == need)
            {
                if(r-l+1 < resLen)
                {
                    resLen = r-l+1;
                    start = l;
                }

                if(countT.contains(s[l]))
                {
                    window[s[l]]--;

                    if(window[s[l]]<countT[s[l]])
                        have--;
                }
                l++;
            }
        }
        if(start==-1)
            return "";
        
        return s.substr(start,resLen);
    }
};
