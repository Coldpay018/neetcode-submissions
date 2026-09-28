class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1)
            return nums[0] == target? 0:-1;
        int low = 0;
        int high = nums.size()-1;
        int first = nums[0];
        int m;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid]>=first)
            {
                low = mid + 1;
                if(low>=nums.size())
                {
                    m = 0;
                    break;
                }
            }
                        
            else
            {
                if(nums[mid]<nums[mid-1])
                {
                    m = mid;
                    break;
                }
                high = mid - 1; 
            }
        }

        if(nums[m]==target)
            return m;
        else if(first>target)
        {
            low = m;
            high = nums.size()-1;
        }
        else
        {
            if(m!=0)
            {
                low = 0;
                high = m-1;
            }
            else
            {
                low = 0;
                high = nums.size()-1;
            }
            
        }

        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                low = mid+1;
            else
                high = mid - 1;
        }
        return -1;

        
    }
};
