class Solution {
public:

    void merge(int low, int mid, int high, vector<int>& nums)
    {
        vector<int> temp(high-low+1);
        int i = low;
        int j = mid+1;
        int k = 0;
        while(i<=mid && j<=high)
        {
            if(nums[i]<=nums[j])
            {
                temp[k]=nums[i];
                i++;
            }
            else 
            {
                temp[k]=nums[j];
                j++;
            }
            k++;
        }
        while(i<=mid)
        {
            temp[k]=nums[i++];
            k++;
        }
        while(j<=high)
        {
            temp[k] = nums[j++];
            k++;
        }
        for(int i = low; i<=high; i++)
        {
            nums[i] = temp[i-low];
        }
    }
    vector<int> mergeSort(int low, int high, vector<int>& nums)
    {
        int l = low;
        int h = high;
        if(l<h)
        {
            int mid = l + (h-l)/2;
            mergeSort(l,mid,nums);
            mergeSort(mid+1,h,nums);
            merge(l,mid,h,nums);
        }
        return nums;
    }
    vector<int> sortArray(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        return mergeSort(low, high, nums);
    }
};