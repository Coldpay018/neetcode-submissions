class Solution {
public:
    int max(int a, int b)
    {
        if(a>b)
            return a;
        return b;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int x1 = text1.length();
        int x2 = text2.length();
        int dp[x1+1][x2+1];

        for(int i=0; i<=x1; i++)
        {
            dp[i][0]=0;
        }

        for(int j=0; j<=x2; j++)
        {
            dp[0][j]=0;
        }
        
        for(int i=1; i<=x1; i++)
        {
            for(int j = 1; j<=x2; j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[x1][x2];
    }
};
