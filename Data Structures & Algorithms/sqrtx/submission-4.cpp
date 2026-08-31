class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;
        int low = 0;
        int high = x;

        while(low<=high)
        {
            int mid = low+(high-low)/2;
            long long sq = 1LL * mid* mid;
            if(sq==x)
                return mid;
            else if(sq<x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};