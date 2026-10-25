class Solution {
public:
    bool valid(vector<int>& piles, int h, int mid)
    {
        long long t = 0;
        for(int i=0; i<piles.size(); i++)
        {
            if(piles[i]>mid)
            {
                if(piles[i]%mid>0)
                    t+=(piles[i]/mid) + 1;
                else
                    t+=(piles[i]/mid);
            }
            else
            {
                t++;
            }
        }
        return t<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(valid(piles, h, mid))
            {
                ans = min(ans,mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
