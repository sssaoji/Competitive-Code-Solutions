class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int t=0;
        for(auto i: tasks)
        {
            mp[i]++;
        }
        priority_queue<int>pq;
        queue<pair<int,int>>q;
        for(auto &i:mp)
        {
            pq.push(i.second);
        }
        while(pq.size()||q.size())
        {
            t++;
            if(pq.size())
            {
                int val = pq.top();
                pq.pop();
                if(val-1!=0)
                {
                    q.push({val-1,t+n});
                }
            }
            int front = q.front().second;
            if(front==t)
            {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return t;
    }
};