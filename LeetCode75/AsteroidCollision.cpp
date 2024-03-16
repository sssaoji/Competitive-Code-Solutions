class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<ast.size();i++)
        {
            if(st.empty())
            {
                st.push(ast[i]);
            }
            else if(ast[i]<0&&st.top()>0)
            {
                bool rep = false;
                int temp;
                while(!st.empty()&&ast[i]<0&&st.top()>0)
                {
                    if(abs(ast[i])>abs(st.top()))
                    {
                        st.pop();
                        rep=true;
                        temp=ast[i];
                    }
                    else if(abs(ast[i])==abs(st.top()))
                    {
                        st.pop();
                        rep=false;
                        break;
                    }
                    else
                    {
                        rep=false;
                        break;
                    }
                }
                if(rep)
                {
                    st.push(temp);
                }
            }
            else
            {
                cout<<ast[i]<<" ";
                st.push(ast[i]);
            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};