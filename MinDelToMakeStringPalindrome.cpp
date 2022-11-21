//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

int minDeletions(string s1, int n)
{
    string s2 = string(s1.rbegin(), s1.rend());
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
    return n - mx[x][y];
}