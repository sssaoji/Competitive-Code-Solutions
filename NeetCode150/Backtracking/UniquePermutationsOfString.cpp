//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    set<string>ans;
    map<int,int>mp;
public:
    void soln(string S, string pasd)
    {
        if(pasd.length()==S.length())
        {
            ans.insert(pasd);
            return;
        }
        for(int i=0;i<S.length();i++)
        {
            if(mp[i]==0)
            {
                pasd+=S[i];
                mp[i]=1;
                soln(S,pasd);
                pasd.erase(pasd.length()-1,1);
                mp[i]=0;
            }
        }
    }
    vector<string>find_permutation(string S)
    {
        string pasd="";
        soln(S, pasd);
        vector<string>temp;
        //  sort(ans.begin(), ans.end());
        //  ans.erase(unique(ans.begin(), ans.end()), ans.end());
        for(string i: ans)
        {
            temp.push_back(i);
        }
        return temp;
    }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        sort(ans.begin(),ans.end());
        for(auto i: ans)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

// } Driver Code Ends