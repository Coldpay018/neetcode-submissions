class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        if(s1.size()>s2.size())
            return false;
        unordered_map<char, int> mp;

        for(char i : s1)
        {
            mp[i]++;
        }
        unordered_map<char,int> temp;
        for(int i=0; i<=s2.size()-n; i++)
        {
            temp = mp;
            for(int j=i; j<i+n; j++)
            {
                temp[s2[j]]--;
            }
            int flag = 0;
            for(const auto& [key,val] : temp)
            {
                if(temp[key]!=0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0)
                return true;
        }
        return false;
    }
};
