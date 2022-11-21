//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int minOperations(string s1, string s2)
    {
        int x = s1.length();
        int y = s2.length();
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
        int dl = x - mx[x][y];
        int ins = y - mx[x][y];
        return dl + ins;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        Solution ob;
        cout << ob.minOperations(s1, s2) << "\n";
    }
    return 0;
}

// } Driver Code Ends