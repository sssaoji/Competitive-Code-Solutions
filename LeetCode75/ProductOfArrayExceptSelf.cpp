class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int siz = nums.size();
        vector<int> l(siz + 2, 1), r(siz + 2, 1);
        vector<int> ans(siz, 1);

        for(int i = 1; i < siz + 1; i++) {
            l[i] = nums[i - 1] * l[i - 1];
        }


        for(int i = siz; i >= 1; i--) {
            r[i] = nums[i - 1] * r[i + 1];
        }


        for(int i = 0; i < siz; i++) {
            ans[i] = l[i] * r[i + 2];
        }
        return ans;
    }
};