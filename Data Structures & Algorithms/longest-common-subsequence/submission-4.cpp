class Solution {
public:
    vector<vector<int>> dp;
    int f(int m, int n, string &text1, string &text2)
    {
        if(m<0 || n<0)
            return 0;

        if(dp[m][n]!=-1)
            return dp[m][n];
            
        if(text1[m]==text2[n])
            return dp[m][n] = 1 + f(m-1,n-1,text1,text2);
        return dp[m][n] = 0 + max(f(m-1,n,text1,text2), f(m,n-1,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
       int m = text1.size();
       int n = text2.size();

       dp.assign(m,vector<int>(n,-1));
       return f(m-1,n-1,text1,text2);


    }
};
