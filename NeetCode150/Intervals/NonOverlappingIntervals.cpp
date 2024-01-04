class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        vector<int>curr;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>pq;
        for(int i=0;i<intervals.size();i++)
        {
            pq.push({intervals[i][0], intervals[i][1]});
        }
        if(pq.size()>0)
        {
            curr.push_back(pq.top().first);
            curr.push_back(pq.top().second);
            pq.pop();
        }
        while(pq.size())
        {
            auto i = pq.top();
            if(curr[1]>i.first)
            {
                int a = max(curr[0], i.first);
                int b = min(curr[1], i.second);
                curr.clear();
                curr.push_back(a);
                curr.push_back(b);
                pq.pop();
            }
            else
            {
                ans.push_back(curr);
                curr.clear();
                curr.push_back(i.first);
                curr.push_back(i.second);
            }
        }
        ans.push_back(curr);
        return intervals.size()-ans.size();
    }
};