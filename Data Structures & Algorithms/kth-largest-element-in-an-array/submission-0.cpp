class Solution {

    struct Desc{
        bool operator()(int a, int b)
        {
            return a > b;
        }   
    };
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        Desc obj;
        sort(nums.begin(),nums.end(), obj);
        return nums[k-1];
    }
};
