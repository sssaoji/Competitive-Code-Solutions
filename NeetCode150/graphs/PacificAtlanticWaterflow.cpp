class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>&heights, vector<vector<bool>> &vstd)
    {
        if(vstd[row][col])
        {
            return;
        }
        vstd[row][col]=true;
        int arr[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<4;i++)
        {
            int nr = row+arr[i][0];
            int nc = col+arr[i][1];
            if(nr>=0&&nc>=0&&nr<heights.size()&&nc<heights[0].size())
            {
                if(heights[row][col]<=heights[nr][nc])
                {
                    dfs(nr,nc, heights, vstd);
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int row = heights.size();
        int col = heights[0].size();
        vector<vector<bool>>vstdAt(row, vector<bool>(col, false));
        vector<vector<bool>>vstdPf(row, vector<bool>(col, false));
        vector<vector<int>>ans;
        for(int i=0;i<row;i++)
        {
            dfs(i, 0, heights, vstdPf);
            dfs(i, col-1, heights,vstdAt);
        }
        for(int i=0;i<col;i++)
        {
            dfs(0, i, heights, vstdPf);
            dfs(row-1, i, heights,vstdAt);
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(vstdAt[i][j]&&vstdPf[i][j])
                {
                    vector<int>a;
                    a.push_back(i);
                    a.push_back(j);
                    ans.push_back(a);
                }
            }
        }
        return ans;
    }
};