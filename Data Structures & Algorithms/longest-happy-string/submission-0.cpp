class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>, vector<pair<int,char>>> max_heap;

        vector<pair<int,char>> arr = {{a,'a'},{b,'b'},{c,'c'}};
        for(auto& i : arr)
        {
            if(i.first > 0)
                max_heap.push(i);
        }
        int n = a + b + c;
        string ans = "";
        int index = 0;
        while (max_heap.empty()==false)
        {
            pair<int, char> p = max_heap.top();
            max_heap.pop();
            if(index==0 || index == 1)
            {
                ans.push_back(p.second);
                p.first--;
            }
            else
            {
                if(ans[index-1] == ans[index-2]  && ans[index-2] == p.second)
                {
                    if(max_heap.empty())
                        break;
                    pair<int, char> q = max_heap.top();
                    max_heap.pop();
                    ans.push_back(q.second);
                    q.first--;
                    if(q.first>0)
                        max_heap.push(q);
                }
                else
                {
                    ans.push_back(p.second);
                    p.first--;
                }
            }
            if(p.first>0)
                max_heap.push(p);
            index++;
        }
        return ans;
    }
};