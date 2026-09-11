class Solution {
public:
    struct compare{
        bool operator()(vector<int>& a, vector<int>& b){
            return a[1] > b[1];
        }
    };
    struct compare1{
        bool operator()(vector<int>& a, vector<int>& b){
            return a[2] > b[2];
        }
    };
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<vector<int>, vector<vector<int>>, compare> min_heap_1;
        priority_queue<vector<int>, vector<vector<int>>, compare1> min_heap_2;

        for(auto& i : trips)
        {
            min_heap_1.push(i);
            min_heap_2.push(i);
        }

        int current_time = 0;
        int cap = 0;
        while(!min_heap_2.empty())
        {
            if(current_time == min_heap_2.top()[2])
            {
                while(!min_heap_2.empty() && current_time == min_heap_2.top()[2])
                {
                    cap-=min_heap_2.top()[0];
                    min_heap_2.pop();
                }
            }

            if(!min_heap_1.empty() && current_time == min_heap_1.top()[1])
            {
                while(!min_heap_1.empty() && current_time == min_heap_1.top()[1])
                {
                    vector<int> next = min_heap_1.top();
                    min_heap_1.pop();

                    if(next[0]>capacity)
                    return false;
                
                    cap+=next[0];
                    if(cap>capacity)
                        return false;
                }
            }
            int a = INT_MAX;
            int b = INT_MAX;

            if(!min_heap_1.empty())
                a = min_heap_1.top()[1];
                
            if(!min_heap_2.empty())
                b = min_heap_2.top()[2];
            
            current_time = min(a,b);
        }
        return true;
    }
};