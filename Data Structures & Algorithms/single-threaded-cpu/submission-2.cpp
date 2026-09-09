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
        int iterator = 0;
        int time = tasks[0][0];
        while(ans.size()!=tasks.size())
        {
            while(iterator<tasks.size() && tasks[iterator][0]<=time)
            {
                min_heap.push(tasks[iterator]);
                iterator++;
            }

            if(min_heap.empty())
            {
                time = tasks[iterator][0];
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