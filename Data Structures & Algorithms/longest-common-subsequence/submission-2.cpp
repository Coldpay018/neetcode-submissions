class Solution {
public:
    vector<vector<int>> dp;
    int f(int n, int m, string &text1, string &text2)
    {
        if(n<0 || m<0)
            return 0;

        if(dp[n][m]!=-1)
            return dp[n][m];
            
        if(text1[n]==text2[m])
            return dp[n][m] = 1 + f(n-1,m-1,text1,text2);
        return dp[n][m] = 0 + max(f(n-1,m,text1,text2), f(n,m-1,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
       int n = text1.size();
       int m = text2.size();

       dp.assign(n,vector<int>(m,-1));
       return f(n-1,m-1,text1,text2);


    }
};
