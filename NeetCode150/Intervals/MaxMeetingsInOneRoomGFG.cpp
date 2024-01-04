//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<vector<int>>intervals;
        for(int i=0;i<n;i++)
        {
            vector<int>hg;
            hg.push_back(start[i]);
            hg.push_back(end[i]);
            intervals.push_back(hg);
            hg.clear();
        }
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
            auto i=pq.top();
            if(curr[1]>=i.first)
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
        return ans.size();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends