#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int size = arr.size();
        int mat[size + 1][sum + 1];
        for (int i = 0; i < size + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
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
        for (int i = 1; i < size + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
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
        return mat[size][sum] == 1 ? true : false;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0;
}
