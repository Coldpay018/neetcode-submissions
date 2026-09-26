class Solution {
public:
    bool works(vector<int>& weights, int days, int mid)
    {
        int d = 0;
        int i=0;
        while(i<weights.size())
        {
            if(weights[i]<mid && i<=weights.size()-2)
            {
                int count = weights[i];
                while(i+1<weights.size() && count + weights[i+1]<=mid)
                {
                    count+=weights[i+1];
                    i++;
                }
                i++;
                d++;
            }
            else
            {
                d++;
                i++;
            }
        }
        if(d<=days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for(int i: weights)
            high+=i;
        
        int ans;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(works(weights, days, mid)==true)
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