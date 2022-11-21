//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int LongestRepeatingSubsequence(string s1)
    {
        string s2 = s1;
        int x = s1.length();
        int y = x;
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
                if (s1[i - 1] == s2[j - 1] && (i != j))
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
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.LongestRepeatingSubsequence(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends