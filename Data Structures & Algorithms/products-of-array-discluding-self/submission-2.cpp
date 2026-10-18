class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul=1;
        int flag=0;
        int mul1 = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0)
                flag++;
            else
                mul = mul * nums[i];
        }
        vector<int> ans(nums.size(),0);
        if(ans==nums)
            return ans;
        if(flag==1)
        {
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i]!=0)
                    continue;
                else
                    ans[i] = mul;
            }
            return ans;
        }
        if(flag>1)
        {
            return ans;
        }
        for(int i=0; i<nums.size(); i++)
        {
            ans[i] = mul / nums[i];
        }
        return ans;
    }
};
