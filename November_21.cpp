class Solution {
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    void markGuardedCells(vector<vector<int>>& grid, int i, int j) {
        for (auto dir : directions) {
            int x = i, y = j;
            while (true) {
                x += dir.first;
                y += dir.second;
                
                if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 2 || grid[x][y] == 3) {
                    break;
                }
                
                if (grid[x][y] == 1) {
                    grid[x][y] = 0;
                }
            }
        }
    }
    
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 1));
        
        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 2;
        }
        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = 3;
        }
        
        for (auto& guard : guards) {
            markGuardedCells(grid, guard[0], guard[1]);
        }
        
        int unguardedCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    unguardedCount++;
                }
            }
        }
        
        return unguardedCount;
    }
};
