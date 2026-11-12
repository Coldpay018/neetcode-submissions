class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int j = s.size()-1;
        while(i<j)
        {
            char a = s[i];
            char b = s[j];
            s[i] = b;
            s[j] = a;
            i++;
            j--;
        }
        return;
    }
};