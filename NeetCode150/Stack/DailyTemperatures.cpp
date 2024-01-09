class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        vector<int>arr(temperatures.size(), 0);
        for(int i=0;i<temperatures.size();i++)
        {
            if(!st.empty()&&temperatures[i]>st.top().first)
            {
                while(!st.empty()&&temperatures[i]>st.top().first)
                {
                    arr[st.top().second]=i-st.top().second;
                    st.pop();
                }
                st.push({temperatures[i], i});
            }
            else
            {
                st.push({temperatures[i], i});
            }
        }
        return arr;
    }
};