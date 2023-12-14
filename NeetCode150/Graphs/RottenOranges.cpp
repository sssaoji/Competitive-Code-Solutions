class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int ans=0;
        int ocnt=0;
        int col=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    ocnt++;
                }
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                }
            }
        }
        while(q.size())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int ad=q.front().second;
            int arr[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
            for(int i=0;i<4;i++)
            {
                int newr=r+arr[i][0];
                int newc=c+arr[i][1];
                if(newr>=0&&newc>=0&&newr<row&&newc<col)
                {
                    if(grid[newr][newc]==1)
                    {
                        ocnt--;
                        grid[newr][newc]=2;
                        q.push({{newr,newc},ad+1});
                        ans = max(ans, ad + 1);
                    }
                }
            }
            q.pop();
        }
        return ocnt==0?ans:-1;
    }
};