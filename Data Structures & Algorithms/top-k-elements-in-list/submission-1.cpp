class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> temp;
        int key;
        int i=0;
        sort(nums.begin(), nums.end());
        while(i<nums.size())
        {
            key = nums[i];
            int count = 1;
            i++;
            while(i<nums.size() && nums[i]==key)
            {
                count++;
                i++;
            }
            temp.push_back({key,count});
        }
        sort(temp.begin(), temp.end(), [](const auto& a, const auto& b){
            return a.second>=b.second;
        });
        i=0;
        vector<int> ans;
        while(i<k)
        {
            ans.push_back(temp[i].first);
            i++;
        }
            
        return ans;
    }
};
