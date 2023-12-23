class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int>mp;
        int i=0;
        int j=0;
        int cnt=0;
        int ans=0;
        while(j<s.length())
        {
            mp[s[j]]++;
            cnt++;
            if(mp[s[j]]>1)
            {
                while(mp[s[j]]>1)
                {
                    mp[s[i]]--;
                    cnt--;
                    if(mp[s[i]]==0)
                    {
                        mp.erase(mp[s[i]]);
                    }
                    i++;
                }
            }
            ans = max(ans, cnt);
            j++;
        }
        return ans;
    }
};