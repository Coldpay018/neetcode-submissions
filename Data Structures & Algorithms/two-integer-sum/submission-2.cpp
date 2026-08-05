class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp_nums;
        for(int i=0; i<nums.size(); i++)
        {
            if(mp_nums.contains(target - nums[i]))
                return{min(i,mp_nums[target-nums[i]]), max(i,mp_nums[target-nums[i]])};
            mp_nums[nums[i]]=i;
        }
    }
};
