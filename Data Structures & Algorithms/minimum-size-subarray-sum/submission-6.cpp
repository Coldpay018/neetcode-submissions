class Solution {
public:

    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int left = 0;
        int right = 0;
        int length = INT_MAX;
        while(right<=nums.size())
        {
            if(sum>=target)
            {
                length = min(length,right - left);
                sum-=nums[left];
                left++;
            }
            else
            {
                if(right==nums.size())
                    break;
                sum+=nums[right];
                right++;
            }
        }
        if(length==INT_MAX)
            return 0;
        return length;
    }
};