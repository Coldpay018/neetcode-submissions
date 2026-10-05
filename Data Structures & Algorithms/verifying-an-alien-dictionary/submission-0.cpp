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
            vector<int> v(words.size(),-1);
            for(int j=0; j<curr.size(); j++)
            {
                for(int k=i+1; k<words.size(); k++)
                {
                    if(j>=words[k].size() || v[k]==0)
                        continue;
                    
                    int a = indexOf(order, words[k][j]);
                    int b = indexOf(order, curr[j]);
                    if(a!=b)
                    {
                        if(a<b)
                            return false;
                        v[k] = 0;
                        
                    }

                    if(curr.substr(0,j+1) == words[k] && curr.size()>words[k].size())
                        return false; 
                }
            }
        }
        return true;
    }
};