class Solution {
public:
    vector<int> Palindromecheck(const string& a)
    {
        int i = 0;
        int j = a.length()-1;

        while(i<j)
        {
            if(isalnum(a[i]) && isalnum(a[j]))
            {
                if(tolower(a[i]) != tolower(a[j]))
                    return {i,j};
            }
            else if(isalnum(a[i]))
            {
                j--;
                continue;
            }
            else if(isalnum(a[j]))
            {
                i++;
                continue;
            }
            i++;
            j--;
        }
        return {-1};
    }
    bool validPalindrome(string s) {
        vector<int> result = Palindromecheck(s);
        if(result.size()==1)
            return true;
        string temp1 = s.substr(0,result[0]) + s.substr(result[0]+1,s.length());
        string temp2 = s.substr(0,result[1]) + s.substr(result[1]+1,s.length());
        vector<int> result1 = Palindromecheck(temp1);
        vector<int> result2 = Palindromecheck(temp2);
        if(result1.size()==1 || result2.size()==1)
            return true;
        return false;
    }
};