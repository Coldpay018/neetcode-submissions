class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_day = 0;
        int profit = 0;

        for(int i=0; i<prices.size(); i++)
        {
            buy_day = i;
            for(int j= i+1; j<prices.size(); j++)
            {
                profit = max(profit, prices[j]-prices[i]);
            }
        }
        return profit;
    }
};
