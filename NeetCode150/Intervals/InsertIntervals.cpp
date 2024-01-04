class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        for(int i=0;i<intervals.size();i++)
        {
            if(newInterval[0]>intervals[i][1])
            {
                ans.push_back(intervals[i]);
            }
            else if(newInterval[1]<intervals[i][0])
            {
                ans.push_back(newInterval);
                ans.insert(ans.end(), intervals.begin()+i, intervals.end());
                return ans;
            }
            else
            {
                int a = min(intervals[i][0], newInterval[0]);
                int b = max(intervals[i][1], newInterval[1]);
                newInterval.clear();
                newInterval.push_back(a);
                newInterval.push_back(b);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};