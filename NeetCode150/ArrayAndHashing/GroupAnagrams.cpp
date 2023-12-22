class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        // map<string,vector<int>>mp;
        // for(int i=0;i<strs.size();i++)
        // {
        //     string temp = strs[i];
        //     sort(temp.begin(), temp.end());
        //     mp[temp].push_back(i);
        // }
        // for(auto i=mp.begin();i!=mp.end();++i)
        // {
        //     vector<string>st;
        //     for(auto ind: i->second)
        //     {
        //         st.push_back(strs[ind]);
        //     }
        //     ans.push_back(st);
        // }
        // return ans;
        map<string, vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            string mystr(26, '0');
            for(int j=0;j<strs[i].length();j++)
            {
                mystr[strs[i][j]-'a']++;
            }
            mp[mystr].push_back(strs[i]);
        }
        for(auto i=mp.begin();i!=mp.end();++i)
        {
            vector<string> a;
            for(auto j: i->second)
            {
                a.push_back(j);
            }
            ans.push_back(a);
        }
        return ans;

    }
};