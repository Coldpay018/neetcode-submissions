class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // for(int i=0; i<nums.size()-1; i++)
        // {
        //     for(int j=i+1; j<nums.size(); j++)
        //     {
        //         if (nums[i]==nums[j])
        //             return nums[i];
        //     }
        // }
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]==2)
                return nums[i];
        }
        return -1;
    }
};
