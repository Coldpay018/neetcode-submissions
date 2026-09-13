class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX;
        for(int i=0; i<nums.size(); i++)
        {
            int sum = 0;
            for(int j = i; j<nums.size(); j++)
            {
                sum+=nums[j];
                if(sum>=target && j-i+1 < len)
                {
                    len = j-i+1;
                }
            }
        }
        if(len!=INT_MAX)
            return len;
        return 0;
    }
};