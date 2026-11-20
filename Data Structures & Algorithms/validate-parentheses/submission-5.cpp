class Solution {
public:
    bool isValid(string s) {
        vector<char> arr;
        int c = 0;
        while(c<=s.size()-1)
        {
            if(s[c]=='(' || s[c]=='{' || s[c]=='[')
                arr.push_back(s[c]);

            else if(arr.empty()==false && ((s[c]==')' && arr.back()=='(') ||            (s[c]==']' && arr.back()=='[') || (s[c]=='}'   &&  arr.back()=='{')))
                arr.pop_back();
            else 
                return false;

            c++;
        }
        if(arr.empty())
            return true;
        return false;
    }
};
