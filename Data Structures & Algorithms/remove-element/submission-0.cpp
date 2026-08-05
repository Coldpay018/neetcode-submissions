class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size()==0)
            return 0;
        vector<int> temp;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]!=val)
                temp.push_back(nums[i]);
        }
        nums = temp;
        return nums.size();
    }
};