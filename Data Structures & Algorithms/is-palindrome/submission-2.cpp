#include<cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        // for (char& c:s)
        // {
        //     if(c>='A' && c<='Z')
        //         c+=32;
        // }
        int i = 0;
        int j = s.length()-1;
        while(i<j)
        {
            if(isalnum(s[i]) && isalnum(s[j]))
            {
                if(tolower(s[i])!=tolower(s[j]))
                    return false;
            }
            else if(isalnum(s[i]))
            {
                j--;
                continue;
            }
            else if(isalnum(s[j]))
            {
                i++;
                continue;
            }
            i++;
            j--;
        }
        return true;
        
    }
};
