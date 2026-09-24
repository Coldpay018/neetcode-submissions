class Solution {
public:
    bool still_works(vector<int> piles, int& k, int h)
    {
        int i = 0;
        int hr = 0;
        while(i<piles.size())
        {
            if(piles[i]<=k)
            {
                i++;
                hr++;
            }
            else
            {
                hr += piles[i]/k;
                piles[i] = piles[i] % k;
                if(piles[i]==0)
                    i++;

            }
        }
        if(hr<=h)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        int ans;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(still_works(piles, mid, h) == true)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;



        
    }
};
