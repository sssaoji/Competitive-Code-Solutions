class Solution {
    vector<vector<int>>ans;
public:
    void soln(vector<int>&cd, int target, vector<int>temp, int ind, map<int,int>&vstd)
    {
        if(ind<=0||target<0)
        {
            return;
        }
        if(target==0)
        {
            if(ans.size()!=0)
            {
                auto i = ans[ans.size()-1];
                if(lexicographical_compare(i.begin(), i.end(), temp.begin(), temp.end()))
                {
                    ans.push_back(temp);
                }
            }
            else
            {
                ans.push_back(temp);
            }
            return;
        }
        if(target>=cd[ind-1])
        {
            soln(cd, target, temp, ind-1, vstd);
            if(vstd[ind-1]==0)
            {
                temp.push_back(cd[ind-1]);
                vstd[ind-1]=1;
                soln(cd, target-cd[ind-1], temp, ind-1, vstd);
                vstd[ind-1]=0;
            }
        }
        else
        {
            soln(cd, target, temp, ind-1, vstd);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cd, int target) {
        vector<int>temp;
        sort(cd.begin(), cd.end());
        map<int,int>vstd;
        soln(cd, target, temp, cd.size(), vstd);
        return ans;
    }
};