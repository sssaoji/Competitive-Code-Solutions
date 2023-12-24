class Solution {
public:
    string minWindow(string s, string t) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>>pq;
        map<char,int>act, mp;
        int expt=0;
        for(auto i:t)
        {
            act[i]++;
        }
        int l=0;
        int r=0;
        int curr=0;
        expt = act.size();
        while(r<s.length())
        {
            mp[s[r]]++;
            if(act.find(s[r])!=act.end()&& act[s[r]]==mp[s[r]])
            {
                curr++;
            }
            while(curr==expt)
            {
                pq.push({r-l+1,{l,r}});
                if(act.find(s[l])==act.end())
                {
                    mp[s[l]]--;
                    if(mp[s[l]]==0)
                    {
                        mp.erase(s[l]);
                    }
                    l++;
                    pq.push({r-l+1,{l,r}});
                }
                else
                {
                    mp[s[l]]--;
                    if(act[s[l]]-mp[s[l]]==1)
                    {
                        curr--;
                    }
                    if(mp[s[l]]==0)
                    {
                        mp.erase(s[l]);
                    }
                    if(curr==expt)
                    {
                        pq.push({r-l+1,{l,r}});
                    }
                    l++;
                }
            }
            r++;
        }
        return pq.size()==0?"":s.substr(pq.top().second.first,pq.top().first);
    }
};