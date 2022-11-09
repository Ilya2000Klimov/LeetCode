class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0)
            return 0;
        grid[x][y] = 0;
        return 1 + dfs(grid, x+1, y) + dfs(grid, x-1, y) + dfs(grid, x, y+1) + dfs(grid, x, y-1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // create visited array
        int maxArea = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.at(0).size(); j++) {
                if(grid.at(i).at(j) == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        
        return maxArea;
    }
};
