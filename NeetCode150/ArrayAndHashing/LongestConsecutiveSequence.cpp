class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        int ans=0;
        for(auto i: nums)
        {
            mp[i]++;
        }
        for(auto i=mp.begin();i!=mp.end();++i)
        {
            int ch = i->first;
            if(mp.find(ch-1)!=mp.end())
            {
                continue;
            }
            else
            {
                int cnt=1;
                while(mp.find(ch+1)!=mp.end())
                {
                    cnt++;
                    ch++;
                }
                ans = max(cnt,ans);
            }
        }
        return ans;
    }
};