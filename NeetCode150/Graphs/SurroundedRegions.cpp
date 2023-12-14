class Solution {
public:
    void bfs(int row, int col, vector<vector<char>> &board, vector<vector<bool>>&visited)
    {
        visited[row][col]=true;
        int sizr = board.size();
        int sizc = board[0].size();
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
                    if(board[newr][newc]=='O' && !visited[newr][newc])
                    {
                        q.push({newr,newc});
                        visited[newr][newc]=true;
                    }
                }
            }
            q.pop();
        }
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>>visited(row, vector<bool>(col, false));
        for(int i=0;i<row;i++)
        {
            if(board[i][0]=='O')
            {
                bfs(i, 0, board, visited);
            }
            if(board[i][col-1]=='O')
            {
                bfs(i, col-1, board,visited);
            }
        }
        for(int i=0;i<col;i++)
        {
            if(board[0][i]=='O')
            {
                bfs(0, i, board, visited);
            }
            if(board[row-1][i]=='O')
            {
                bfs(row-1, i, board,visited);
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(!visited[i][j]&&board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    }
};