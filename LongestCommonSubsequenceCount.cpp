//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence
int mat[1001][1001];

class Solution
{
public:
    Solution()
    {
        memset(mat, -1, sizeof(mat));
    }
    // Function to find the length of longest common subsequence in two strings.
    int lcsUsingMemoization(int x, int y, string s1, string s2)
    {
        if (x == 0 || y == 0)
        {
            return 0;
        }
        if (mat[x][y] != -1)
        {
            return mat[x][y];
        }
        else if (s1[x - 1] == s2[y - 1])
        {
            return mat[x][y] = (1 + lcsUsingMemoization(x - 1, y - 1, s1, s2));
        }
        else
        {
            return mat[x][y] = max(lcsUsingMemoization(x - 1, y, s1, s2), lcsUsingMemoization(x, y - 1, s1, s2));
        }
    }
    int lcsUsingRecursion(int x, int y, string s1, string s2)
    {
        if (x == 0 || y == 0)
        {
            return 0;
        }
        else if (s1[x - 1] == s2[y - 1])
        {
            return (1 + lcsUsingRecursion(x - 1, y - 1, s1, s2));
        }
        else
        {
            return max(lcsUsingRecursion(x - 1, y, s1, s2), lcsUsingRecursion(x, y - 1, s1, s2));
        }
    }
    int lcsUsingDp(int x, int y, string s1, string s2)
    {
        int mx[x + 1][y + 1];
        for (int i = 0; i < x + 1; i++)
        {
            for (int j = 0; j < y + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    mx[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < x + 1; i++)
        {
            for (int j = 1; j < y + 1; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    mx[i][j] = 1 + mx[i - 1][j - 1];
                }
                else
                {
                    mx[i][j] = max(mx[i - 1][j], mx[i][j - 1]);
                }
            }
        }
        return mx[x][y];
    }
};

//{ Driver Code Starts.
int main()
{
    int t, n, k, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y; // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2; // Take both the string as input
        Solution ob;
        cout << ob.lcsUsingRecursion(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends