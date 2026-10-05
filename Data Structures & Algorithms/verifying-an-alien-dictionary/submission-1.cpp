class Solution {
public:
    int indexOf(string order, char c)
    {
        for(int i=0; i<order.size(); i++)
        {
            if(order[i]==c) 
                return i;
        }
        return -1;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0; i<words.size()-1; i++)
        {
            string curr = words[i];
            vector<int> v={-1,-1};
            for(int j=0; j<curr.size(); j++)
            {
                string next = words[i+1];
                if(j>=next.size() || v[1]==0)
                    continue;
                    
                int a = indexOf(order, next[j]);
                int b = indexOf(order, curr[j]);
                if(a!=b)
                {
                    if(a<b)
                        return false;
                    v[1] = 0;      
                }

                if(curr.substr(0,j+1) == next && curr.size()>next.size())
                    return false; 
            }
        }
        return true;
    }
};