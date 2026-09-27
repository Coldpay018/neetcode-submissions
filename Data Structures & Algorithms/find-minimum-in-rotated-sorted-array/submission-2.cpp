class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size()==1)
            return nums[0];
        
        int first = nums[0];
        int low = 0;
        int high = nums.size()-1;
        int mid;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            if(nums[mid]>=first)
            {
                low = mid + 1;
                if(low>=nums.size())
                    return first;
            }
            else
            {
                if(nums[mid]<nums[mid-1])
                    return nums[mid];
                high = mid - 1;
            }
        }
        return 0;
    }
};
