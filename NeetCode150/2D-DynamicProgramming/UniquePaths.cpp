class Solution {
private:
    int arr[101][101];
public:
    Solution()
    {
        memset(arr, -1, sizeof(arr));
    }
    int ans(int startx, int starty, int endx, int endy)
    {
        if(startx>endx||starty>endy)
        {
            return 0;
        }
        if(startx==endx&&starty==endy)
        {
            return 1;
        }
        if(arr[startx][starty]!=-1)
        {
            return arr[startx][starty];
        }
        return arr[startx][starty]=ans(startx+1, starty, endx, endy)+ans(startx, starty+1, endx, endy);
    }
    int dpans(int m, int n)
    {
        int dp[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=1;
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        return dpans(m, n);
    }
};