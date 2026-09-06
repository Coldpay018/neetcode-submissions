class Solution {
private:
    priority_queue<int> max_heap;
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==0)
            return 0;

        for(int i = 0; i<stones.size(); i++)
            max_heap.push(stones[i]);

        while(max_heap.size() > 1)
        {
            int largest = max_heap.top();
            max_heap.pop();
            int second_largest = max_heap.top();
            max_heap.pop();

            if(abs(largest-second_largest)>0)
                max_heap.push(abs(largest-second_largest));
        }
        if(max_heap.empty())
            return 0;
        return max_heap.top();
    }
};
