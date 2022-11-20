//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
public:
    string printlcs(int x, int y, string s1, string s2)
    {
        int ans = 0;
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
                    ans = max(ans, mx[i][j]);
                }
                else
                {
                    mx[i][j] = 0;
                }
            }
        }
        string s = "";
        for (int i = 0; i < x + 1; i++)
        {
            for (int j = 0; j < y + 1; j++)
            {
                if (mx[i][j] == ans)
                {
                    int a = i;
                    int b = j;
                    while (mx[a][b] != 0)
                    {
                        s += s1[a - 1];
                        a--;
                        b--;
                    }
                }
            }
        }
        reverse(s.begin(), s.end());
        return s;
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
        cout << ob.printlcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends