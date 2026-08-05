#include<string>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        if(strs.size()==1)
            return strs[0];
        string min_element=strs[0];
        for(int i=1; i<strs.size(); i++)
        {
            if(strs[i].length()<min_element.length())
                min_element = strs[i];
        }
        for(int i=0; i<min_element.length(); i++)
        {
            for(int j = 0; j<strs.size(); j++)
            {
                if(strs[j][i]!=min_element[i])
                    return min_element.substr(0,i);
            }
        }
        return min_element;
    }
};