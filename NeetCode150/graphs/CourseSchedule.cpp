class Solution {
public:
    bool dfs(int course, vector<vector<int>>& prerequisites, vector<int> &vstd)
    {
        if(vstd[course]==1)
        {
            return false;
        }
        if(vstd[course]==2)
        {
            return true;
        }
        vstd[course]=1;
        for(int i=0;i<prerequisites[course].size();i++)
        {
            int next = prerequisites[course][i];
            if (!dfs(next, prerequisites, vstd)) {
                return false;
            }
        }
        vstd[course]=2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>arr(numCourses, vector<int>());
        vector<int>vstd(numCourses,0);
        bool z=true;
        for(int i=0;i<prerequisites.size();i++)
        {
            arr[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++)
        {
            z=z&&dfs(i, arr, vstd);
        }
        return z;
    }
};