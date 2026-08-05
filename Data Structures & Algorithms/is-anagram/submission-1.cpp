class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map <char,int> mp1;
        for(int i=0; i<s.length(); i++)
        {
            mp1[s[i]]++;
        }
        for(int i = 0; i<t.length(); i++)
        {
            if(mp1[t[i]]==0)
                return false;
            mp1[t[i]]--;
        }
        return true;

    }
};
