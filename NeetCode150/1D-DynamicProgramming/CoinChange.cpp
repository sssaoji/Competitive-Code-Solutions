class Solution {
public:
    int coinChange(vector<int>& arr, int amount) {
        int sum = 0;
        int N=arr.size();
        int k=amount;
        int mat[N + 1][k + 1];
        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 0; j < k + 1; j++)
            {
                if (i == 0)
                {
                    mat[i][j] = 100000;
                }
                if (j == 0&&i>0)
                {
                    mat[i][j] = 0;
                }
                if(i==1 && j>0)
                {
                    mat[i][j] = j%arr[0]==0?j/arr[0]:100000;
                }
            }
        }
        for (int i = 1; i < N + 1; i++)
        {
            for (int j = 1; j < k + 1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    mat[i][j] = min(1+ mat[i][j - arr[i - 1]], mat[i - 1][j]);
                }
                else
                {
                    mat[i][j] = mat[i - 1][j];
                }
            }
        }
        return mat[N][k]==100000?-1:mat[N][k];
    }
};