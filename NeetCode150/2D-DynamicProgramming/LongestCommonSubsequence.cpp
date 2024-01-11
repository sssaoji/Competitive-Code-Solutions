class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return dplcs(text1, text1.size(), text2, text2.size());
    }
    int lcs(string text1, int l1, string text2, int l2)
    {
        if(l1==0||l2==0)
        {
            return 0;
        }
        if(text1[l1-1]==text2[l2-1])
        {
            return 1+lcs(text1, l1-1, text2, l2-1);
        }
        return max(lcs(text1, l1-1, text2, l2),lcs(text1, l1, text2, l2-1));
    }
    int dplcs(string text1, int l1, string text2, int l2)
    {
        int dp[l1+1][l2+1];
        for(int i=0;i<l1+1;i++)
        {
            for(int j=0;j<l2+1;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<l1+1;i++)
        {
            for(int j=1;j<l2+1;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[l1][l2];
    }
};