class Solution {
public:
    // int max(vector<int>& arr)
    // {
    //     int n = arr.size();
    //     int max = INT_MIN;
    //     for(int i=0; i<n; i++)
    //     {
    //         if(arr[i]>max)
    //             max = arr[i];
    //     }
    //     return max;
    // }
    // int min(vector<int>& arr, int start, int end)
    // {
    //     int min = INT_MAX;
    //     for(int i=start; i<=end; i++)
    //     {
    //         if(arr[i]<min)
    //             min = arr[i];
    //     }
    //     return min;
    // }
    int maxProfit(vector<int>& prices) {
        int buy_day = prices[0];
        vector<int> profits;
        for(int i=0; i<prices.size(); i++)
        {
            buy_day = min(buy_day,prices[i]);
            profits.push_back(prices[i] - buy_day);
        }
        return *max_element(profits.begin(), profits.end());
    }
};
