class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int,int>>pq;
        stack<float>st;
        for(int i=0;i<speed.size();i++)
        {
            pq.push({position[i], speed[i]});
        }
        while(pq.size())
        {
            if(st.empty())
            {
                st.push(float(target-pq.top().first)/float(pq.top().second));
            }
            else
            {
                if(!(st.top()>=float(target-pq.top().first)/pq.top().second))
                {
                    st.push(float(target-pq.top().first)/pq.top().second);
                }
            }
            pq.pop();
        }
        return st.size();
    }
};