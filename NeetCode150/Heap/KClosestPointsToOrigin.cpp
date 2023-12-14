class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>, vector<pair<int, vector<int>>>, greater<>>pq;
        vector<vector<int>>fans;
        int cntr=0;
        for(auto i: points)
        {
            int x = i[0];
            int y = i[1];
            int ans = pow(x,2)+pow(y,2);
            cout<<ans<<" ";
            pq.push({ans, i});
        }
        while(cntr<k)
        {
            fans.push_back(pq.top().second);
            pq.pop();
            cntr++;
        }
        return fans;
    }
};