class Solution {
public:
    bool isValid(string s) {
        map<char,char>mp;
        mp.insert({')','('});
        mp.insert({'}','{'});
        mp.insert({']','['});
        stack<int>st;
        for(auto i: s)
        {
            if(mp.find(i)!=mp.end())
            {
                if(st.size()&&st.top()==mp[i])
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                st.push(i);
            }
        }
        return st.size()==0?true:false;
    }
};