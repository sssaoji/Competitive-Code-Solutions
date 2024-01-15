class Solution {
public:
    vector<vector<int>>ans;
    void soln(vector<int>&candidates, int ind, vector<int>arr, int target)
    {
        if(ind==0||target<0)
        {
            return;
        }
        if(target==0)
        {
            ans.push_back(arr);
            return;
        }
        if(target-candidates[ind-1]>=0)
        {
            soln(candidates, ind-1, arr, target);
            arr.push_back(candidates[ind-1]);
            soln(candidates, ind, arr, target-candidates[ind-1]);
            return;
        }
        else
        {
            soln(candidates, ind-1, arr, target);
            return;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>arr;
        soln(candidates, candidates.size(), arr, target);
        return ans;
    }
};