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
        vector<int> temp = arr;
        while(r<s2.size())
        {
            arr = temp;
            for(int i=l; i<=r; i++)
            {
                if(arr[s2[i]-'a']>0)
                    arr[s2[i]-'a']--;
            }
            int flag=0;
            for(int i=0; i<arr.size(); i++)
            {
                if(arr[i]>0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0)
                return true;
            l++;
            r++;
        }
        return false;
    }
};
