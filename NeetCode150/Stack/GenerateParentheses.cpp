class Solution {
public:
    vector<string>ans;
    void bktr(int open, int close, int n, string str)
    {
        if(n==open && open==close)
        {
            ans.push_back(str);
            return;
        }
        if(open==n && open>close)
        {
            str+=")";
            bktr(open, close+1, n, str);
        }
        else if(open>close)
        {
            string str1="";
            str1=str;
            str+=")";
            str1+="(";
            bktr(open, close+1, n, str);
            bktr(open+1, close, n, str1);
        }
        else if(open==close)
        {
            str+="(";
            bktr(open+1, close, n, str);
        }
    }
    vector<string> generateParenthesis(int n) {
        bktr(0,0,n, "");
        return ans;
    }
};