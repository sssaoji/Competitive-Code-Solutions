#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int perfectSum(int arr[], int N, int k)
    {
        int cnt = 0;
        int mat[N + 1][k + 1];
        int mod = 1e9 + 7;
        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 0; j < k + 1; j++)
            {
                if (i == 0 && j > 0)
                {
                    mat[i][j] = 0;
                }
            }
        }
        mat[0][0] = 1;
        for (int i = 1; i < N + 1; i++)
        {
            for (int j = 0; j < k + 1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    mat[i][j] = (mat[i - 1][j - arr[i - 1]] % mod + mat[i - 1][j] % mod) % mod;
                }
                else
                {
                    mat[i][j] = (mat[i - 1][j]) % mod;
                }
            }
        }
        return mat[N][k];
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";
    }
    return 0;
}