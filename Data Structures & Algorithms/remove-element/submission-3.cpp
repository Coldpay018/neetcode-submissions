class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = 0;
        while(i<nums.size() && j<nums.size())
        {
            if(nums[i]==val)
            {
                while(j<nums.size() && nums[j]==val)
                    j++;
                if(j==nums.size())
                    return i;
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            i++;
            j++;
        }
        return i;
    }
};