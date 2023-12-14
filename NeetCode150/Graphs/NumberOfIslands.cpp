class Solution {
public:
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>>&visited)
    {
        visited[row][col]=true;
        int sizr = grid.size();
        int sizc = grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        while(q.size())
        {
            int rowc = q.front().first;
            int colc = q.front().second;
            int cal[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
            for(int i=0;i<4;i++)
            {
                int newr = rowc + cal[i][0];
                int newc = colc + cal[i][1];
                if(newr<sizr && newc<sizc && newr>=0 && newc>=0)
                {
                    if(grid[newr][newc]=='1' && !visited[newr][newc])
                    {
                        q.push({newr,newc});
                        visited[newr][newc]=true;
                    }
                }
            }
            q.pop();
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>>visited(row, vector<bool>(col, false));
        int cnt=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    cnt++;
                    bfs(i, j, grid, visited);
                }
            }
        }
        return cnt;
    }
};