class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_day = prices[0];
        int profit = 0;

        for(int i=0; i<prices.size(); i++)
        {
            buy_day = min(buy_day, prices[i]);
            profit = max(profit, prices[i] - buy_day);
        }
        return profit;

        
    }
};
