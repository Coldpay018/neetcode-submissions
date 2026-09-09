class Solution {
public:

    struct Compare{
        bool operator()(const vector<int>& a, const vector<int>& b)
        {
            if(a[1]!=b[1])
                return a[1] > b[1];
            else
                return a[2] > b[2];
        }
    };
    vector<int> getOrder(vector<vector<int>>& tasks) {

        int index = 0;
        for(auto& i: tasks)
        {
            i.push_back(index);
            index++;
        }

        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        priority_queue<vector<int>, vector<vector<int>>, Compare> min_heap;

        vector<int> ans;
        
        int time = tasks[0][0];
        while(ans.size()!=tasks.size())
        {
            for(auto& i : tasks)
            {
                if(i[0]<=time && i[2]!=-1)
                {
                    min_heap.push(i);
                    i[2]=-1;
                }
            }
            if(min_heap.empty())
            {
                for(auto& i : tasks)
                {
                    if(i[2]!=-1)
                    {
                        time = i[0];
                        break;
                    }
                }
            }
            else
            {
                ans.push_back(min_heap.top()[2]);
                time+=min_heap.top()[1];
                min_heap.pop();
            }
            
        }
        return ans;
        

    }
};