class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> v(26,-1);
        for(int i=0; i<order.size(); i++)
        {
            v[order[i]-'a'] = i;
        }
        for(int i=0; i<words.size()-1; i++)
        {
            string curr = words[i];

            for(int j=0; j<curr.size(); j++)
            {
                string next = words[i+1];
                if(j>=next.size())
                    break;
                    
                int a = v[next[j]-'a'];
                int b = v[curr[j]-'a'];
                if(a!=b)
                {
                    if(a<b)
                        return false;
                    break;
                }

                if(curr.substr(0,j+1) == next && curr.size()>next.size())
                    return false; 
            }
        }
        return true;
    }
};