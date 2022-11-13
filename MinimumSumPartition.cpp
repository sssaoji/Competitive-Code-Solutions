#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    int minDifference(int arr[], int n)
    {
        int tot = 0;
        int size = n;
        for (int i = 0; i < n; i++)
        {
            tot += arr[i];
        }
        int sum = tot / 2;
        int mat[size + 1][sum + 1];
        for (int i = 0; i < size + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    mat[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < size + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    mat[i][j] = max(arr[i - 1] + mat[i - 1][j - arr[i - 1]], mat[i - 1][j]);
                }
                else
                {
                    mat[i][j] = mat[i - 1][j];
                }
            }
        }
        return tot - (2 * mat[size][sum]);
    }
};
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
}