class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::map<char, std::pair<int, int>> mp;
        std::vector<int> ans;

        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]].second = i;
            } else {
                mp.insert({s[i], {i, i}});
            }
        }
        int i=0;
        int nx = 0;
        int siz=0;
        while (i < s.size()) {
            siz++;
            int nx = max(nx, mp[s[i]].second);
            if(i==nx)
            {
                ans.push_back(siz);
                siz = 0;
            }
            i++;
        }
        return ans;
    }
};