class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int>arr(numCourses,0);
        vector<vector<int>>adj(numCourses, vector<int>());
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
            arr[pre[i][0]]++;
        }
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)
            {
                q.push(i);
            }
        }
        while(q.size())
        {
            int top = q.front();
            ans.push_back(top);
            for(int i=0;i<adj[top].size();i++)
            {
                int a = adj[top][i];
                arr[a]--;
                if(arr[a]==0)
                {
                    q.push(a);
                }
            }
            q.pop();
        }
        return ans;
    }
};