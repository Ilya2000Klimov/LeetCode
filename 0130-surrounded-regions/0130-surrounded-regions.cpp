class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<char>>& ans, int x, int y)
    {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'O' || board[x][y] == ans[x][y]) return;
        ans[x][y] = 'O';
        dfs(board, ans, x+1, y);
        dfs(board, ans, x-1, y);
        dfs(board, ans, x, y+1);
        dfs(board, ans, x, y-1);
    }
    
    void solve(vector<vector<char>>& board)
    {
        int x = board.size();
        int y = board[0].size();
        vector<vector<char>> ans (x, vector<char>(y, 'X'));
        
        for(int i = 0; i < y; i++)
            dfs(board, ans, 0, i);
        
        for(int i = 0; i < y; i++)
            dfs(board, ans, x-1, i);
        
        for(int i = 0; i < x; i++)
            dfs(board, ans, i, 0);
        
        for(int i = 0; i < x; i++)
            dfs(board, ans, i, y-1);
        
        board = ans;
    }
};