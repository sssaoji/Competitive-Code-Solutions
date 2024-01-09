class Solution {
public:
    bool isnum(auto str)
    {
        try
        {
            stoi(str);
            return true;
        }
        catch(const invalid_argument &e){
            return false;
        }
    }
    int ans(int a, int b, string opr)
    {
        if(opr=="+")
        {
            return a+b;
        }
        if(opr=="*")
        {
            return a*b;
        }
        if(opr=="-")
        {
            return a-b;
        }
        return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto i: tokens)
        {
            if(isnum(i))
            {
                st.push(stoi(i));
            }
            else
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(ans(a,b, i));
            }
        }
        return st.top();

    }
};