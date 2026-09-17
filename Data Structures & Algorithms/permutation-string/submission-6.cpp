class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()> s2.size())
            return false;
        if(s1==s2)
            return true;

        int l = 0;
        int r = s1.size()-1;
        vector<int> arr(26,0);
        for(int i=0; i<s1.size(); i++)
        {
            arr[s1[i]-'a']++;
        }
        vector<int> arr2(26,0);
        for(int i=0; i<=r; i++)
        {
            arr2[s2[i]-'a']++;
        }
        while(r+1<s2.size())
        {
            if(arr2==arr)
                return true;
            arr2[s2[l]-'a']--;
            arr2[s2[r+1]-'a']++;
            l++;
            r++;
        }
        if(arr2==arr)
            return true;
        return false;
    }
};
