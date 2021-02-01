//used for composing 4 directions, {-1, 0}, {0, 1}, {1, 0}...
vector<int> directions{-1, 0, 1, 0, -1};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //using stack to store connected parts
        int m = grid.size(), n = m? grid[0].size():0, local_area, area = 0, x, y;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j]){
                    local_area = 1;
                    grid[i][j] = 0;
                    stack<pair<int, int>> island;
                    island.push({i,j});
                    //similar to recursion
                    while(!island.empty()){
                        auto [r, c] = island.top();
                        island.pop();
                        for(int k = 0; k < 4; ++k){
                            x = r + directions[k], y = c + directions[k+1];
                            //find new near area, put in for further searching
                            if(x >= 0 && y >=0 && x < m && y < n && grid[x][y] == 1){
                                grid[x][y] = 0;
                                island.push({x, y});
                                ++local_area;
                            }
                        }
                    }
                    area = max(local_area, area);
                }
            }
        }
        return area;
    }
};

///////////////////////////////////////////////////////////////

//used for composing 4 directions, {-1, 0}, {0, 1}, {1, 0}...
vector<int> directions{-1, 0, 1, 0, -1};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //using recursion
        if(grid.empty() || grid[0].empty()) return 0;
        int max_area = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                max_area = max(max_area, dfs(grid, i, j));
            }
        }
        return max_area;
    }
    
    int dfs(vector<vector<int>>& grid, int r, int c){
        if(grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        int x, y, area = 1;
        for(int i = 0; i < 4; ++i){
            x = r + directions[i], y = c + directions[i+1];
            if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size()){
                area += dfs(grid, x, y);
            }
        }
        return area;
    }
};
