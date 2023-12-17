class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int btm = matrix.size()-1;
        int siz = matrix[0].size()-1;
        while(top<=btm)
        {
            int mid = (top+btm)/2;
            if(matrix[mid][siz]<target)
            {
                top = mid+1;
            }
            else if(matrix[mid][0]>target)
            {
                btm = mid-1;
            }
            else
            {
                top = mid;
                break;
            }
        }
        if (top <= btm) {

            int l = 0;
            int r = siz;
            while (l <= r) {
                int mid1 = (l + r) / 2;
                if (matrix[top][mid1] == target) {
                    return true;
                }
                if (matrix[top][mid1] < target) {
                    l = mid1 + 1;
                } else if (matrix[top][mid1] > target) {
                    r = mid1 - 1;
                }
            }
            return false;
        } else return false;
    }
};