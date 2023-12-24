class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        map<char,int>mp;
        int ans=0;
        auto compare = [](const auto& a, const auto& b) {
            return a.second < b.second;
        };
        while(j<s.length())
        {
            mp[s[j]]++;
            auto mx_val = max_element(mp.begin(), mp.end(), compare);
            if((j-i+1)-mx_val->second<=k)
            {
                ans = max(ans, (j-i+1));
            }
            else if((j-i+1)-mx_val->second>k)
            {
                while((j-i+1)-mx_val->second>k)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                    mx_val = max_element(mp.begin(), mp.end(), compare);
                }
            }
            j++;
        }
        return ans;
    }
};