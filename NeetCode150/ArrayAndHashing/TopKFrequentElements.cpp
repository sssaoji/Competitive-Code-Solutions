class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        // priority_queue<pair<int,int>>pq;
        // for(auto i:nums)
        // {
        //     mp[i]++;
        // }
        // for(auto i=mp.begin();i!=mp.end();++i)
        // {
        //     pair<int, int>pr;
        //     int fq = i->second;
        //     int nm = i->first;
        //     pq.push({fq,nm});
        // }
        // while(k>0)
        // {
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        //     k--;
        // }
        // return ans;
        vector<vector<int>>vtr(nums.size());
        map<int,int>mp;
        for(int i: nums)
        {
            mp[i]++;
        }
        for(auto i=mp.begin();i!=mp.end();++i)
        {
            vtr[i->second-1].push_back(i->first);
        }
        for(auto i=vtr.rbegin();i!=vtr.rend();++i)
        {
            for(auto j: *i)
            {
                if(k>0)
                {
                    ans.push_back(j);
                    k--;
                }
            }
        }
        return ans;
    }
};