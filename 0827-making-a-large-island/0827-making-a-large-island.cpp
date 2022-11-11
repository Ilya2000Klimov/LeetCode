// class Solution {
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
        
//     }
// };

class Solution {
public:

    vector<int> xOffsets={1, -1, 0, 0};
    vector<int> yOffsets={0, 0, 1, -1};
    int dfs(vector<vector<int>>& grid, int x, int y, int color) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1) return 0;
        grid[x][y] = color;
        return 1 + dfs(grid, x+1, y, color) + dfs(grid, x-1, y, color) + dfs(grid, x, y+1, color) + dfs(grid, x, y-1, color);
}


    int largestIsland(vector<vector<int>>& grid) {
        int N = grid.size();
        int n = grid.at(0).size();
        unordered_map<int,int> area; 
        area[0] = 0;

        int maxArea = 0;
        int currArea = 0;
        int color = 2;

        for(int i = 0 ; i < N; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    currArea = dfs(grid, i, j, color);
                    area[color] = currArea;
                    color++;
                }
            }
        }
        
        vector<int> colors;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    currArea = 1;
                    colors.clear();
                    for(int k = 0; k < 4; k++) {
                        int xCoord = i+xOffsets[k];
                        int yCoord = j+yOffsets[k];
                        if(!(xCoord<0 || xCoord>=N || yCoord<0 || yCoord>=n)) {
                            if(count(colors.begin(), colors.end(), grid[xCoord][yCoord]) == 0) {
                                currArea += area[grid[xCoord][yCoord]];   
                                colors.emplace_back(grid[i+xOffsets[k]][j+yOffsets[k]]);
                            }
                        }
                    }
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        
        // If maxArea is 0, either original grid is full of 0's or full of 1's
        if(maxArea == 0) {
            if(grid[0][0] == 0) return 0;
            return N*n;
        }
        
        return maxArea;
    }
};

// void calc(vector<vector<int>>& grid,int i,int j,int& currArea,int& n,int& color) {
//     currArea++;
//     grid[i][j] = color;
//     for(int k = 0)
// }



/* TODO
    Store Area of island
    Create function calculate largest island
        Declare new variables(current area)
        increment current area
        create for loop to check if x < 0 or y < 0
        declare has map for area
        max area = 0 and current area = 0
        iterate through island
*/