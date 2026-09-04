class Solution {
public:
    int arrangeCoins(int n) {
        long long rows = 0;
        int i = 0;
        long long temp = 0;
        while(rows + (temp+1)<=n)
        {
            temp++;  
            rows+=temp;
            i++;
        }
        return i;
    }
};