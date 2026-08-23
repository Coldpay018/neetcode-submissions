class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for(int i=0; i<n; i++)
        {
            if(mp[nums[i]]>(n/2))
                return nums[i];
        }
        return 0;

    }
};