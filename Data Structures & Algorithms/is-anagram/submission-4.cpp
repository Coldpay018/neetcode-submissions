class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        vector<int> letters(27,0);
        for(int i=0; i<s.size(); i++)
        {
            letters[s[i]-'a']++;
        }
        for(int i=0; i<t.size(); i++)
        {
            letters[t[i]-'a']--;
        }
        vector<int> temp(27,0);
        if (temp==letters)
            return true;
        return false;
    }
};
