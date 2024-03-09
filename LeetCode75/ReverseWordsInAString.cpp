class Solution {
public:
    string reverseWords(string s) {
        istringstream lineStream(s);
        string w;
        vector<string> ans;
        string fans="";
        while(lineStream >> w)
        {
            ans.push_back(w);
        }
        for(int i=ans.size()-1;i>=0;i--)
        {
            fans+=ans[i];
            if(i!=0)
            {
                fans+=" ";
            }
        }
        return fans;
    }
};