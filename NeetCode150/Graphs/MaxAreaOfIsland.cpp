class Solution {
public:
    int bfs(int row, int col, vector<vector<int>> &grid, vector<vector<bool>>& vstd)
    {
        vstd[row][col]=true;
        queue<pair<int,int>>q;
        int sr = grid.size();
        int sc = grid[0].size();
        int qm = 1;
        q.push({row,col});
        while(q.size())
        {
            int cx = q.front().first;
            int cy = q.front().second;
            int arr[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
            for(int i=0;i<4;i++)
            {
                int nr = cx+arr[i][0];
                int nc = cy+arr[i][1];
                if(nr>=0 && nc>=0 && nr<sr&&nc<sc)
                {
                    if(grid[nr][nc]==1&&!vstd[nr][nc])
                    {
                        vstd[nr][nc]=true;
                        q.push({nr,nc});
                        qm++;
                    }
                }
            }
            q.pop();
        }
        return qm;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>>vstd(row, vector<bool>(col, false));
        int ans=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1 && !vstd[i][j])
                {
                    int z = bfs(i,j,grid,vstd);
                    ans = max(ans,z);
                }
            }
        }
        return ans;
    }
};