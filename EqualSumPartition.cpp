#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }
        if (sum % 2 != 0)
        {
            return 0;
        }
        int k = sum / 2;
        int mat[N + 1][k + 1];
        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 0; j < k + 1; j++)
            {
                if (i == 0 && j > 0)
                {
                    mat[i][j] = 0;
                }
                if (j == 0)
                {
                    mat[i][j] = 1;
                }
            }
        }
        for (int i = 1; i < N + 1; i++)
        {
            for (int j = 1; j < k + 1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    mat[i][j] = mat[i - 1][j - arr[i - 1]] || mat[i - 1][j];
                }
                else
                {
                    mat[i][j] = mat[i - 1][j];
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
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}