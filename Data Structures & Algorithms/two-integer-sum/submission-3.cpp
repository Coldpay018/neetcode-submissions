class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp_nums;
        for(int i=0; i<nums.size(); i++)
        {
            if(mp_nums.contains(target - nums[i]))
                return{mp_nums[target-nums[i]], i};
            mp_nums[nums[i]]=i;
        }
    }
};
