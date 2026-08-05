class Solution {
public:
        struct Result
        {
            int start;
            int end;
            int sum;
        };

        Result findCrossingSubarray(const vector<int>& arr, int low, int mid, int high)
        {
            int leftSum = INT_MIN;
            int sum = 0;
            int bestLeft = mid;
            
            for(int i=mid; i>=low; i--)
            {
                sum+=arr[i];
                
                if(sum > leftSum)
                {
                    leftSum = sum;
                    bestLeft = i;
                }
            }
            
            int rightSum = INT_MIN;
            sum = 0;
            int bestRight = mid + 1;
            
            for(int i = mid + 1; i<=high; i++)
            {
                sum+=arr[i];
                if(sum>rightSum)
                {
                    rightSum = sum;
                    bestRight = i;
                }
            }
            return {bestLeft, bestRight, leftSum + rightSum};
        }

        Result findMaximumSubarray(const vector<int>& arr, int low, int high)
        {
            if(low==high)
                return {low, high, arr[low]};
                
            int mid = low + (high-low)/2;
            
            Result leftResult = findMaximumSubarray(arr, low, mid);
            Result rightResult = findMaximumSubarray(arr, mid + 1, high);
            
            Result crossingResult = findCrossingSubarray(arr,low,mid,high);
            
            if(leftResult.sum >= rightResult.sum && leftResult.sum >= crossingResult.sum)
                return leftResult;
            
            if(rightResult.sum >= leftResult.sum && rightResult.sum >= crossingResult.sum)
                return rightResult;
            
            return crossingResult;
        }

    int maxSubArray(vector<int>& nums) {
        Result answer = findMaximumSubarray(nums, 0, nums.size()-1);
        return answer.sum;
    }
};
