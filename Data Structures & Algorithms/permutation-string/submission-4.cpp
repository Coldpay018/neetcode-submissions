class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
            return false;
        int l = 0;
        int r = s1.size()-1;
        vector<int> arr(26,0);
        vector<int> temp(26,0);
        vector<int> temp2(26,0);
        for(int i=0; i<s1.size(); i++)
        {
            arr[s1[i]-'a']++;
        }
        int flag = 0;
        while(r<s2.size())
        {
            temp = arr;
            if(temp[s2[r]-'a']==0)
            {
                l = r + 1;
                r = l + s1.size() - 1;
                continue;
            }
            for(int i=l; i<=r; i++)
            {
                temp[s2[i]-'a']--;
            }
            if(temp == temp2)
            {
                flag = 1;
                break;
            }
            else
            {
                l+=1;
                r+=1;
            }
            
        }
        if(flag==1)
            return true;
        return false;
    }
};
