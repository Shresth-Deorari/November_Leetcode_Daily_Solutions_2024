class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> visited(m, vector<int>(n, 0));

        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        
        while (!pq.empty()) {
            int cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            
            if (x == m - 1 && y == n - 1) {
                return cost;
            }
            
            if (visited[x][y]) continue;
            visited[x][y] = 1;
            
            for (auto dir : directions) {
                int newx = x + dir.first;
                int newy = y + dir.second;
                if (newx >= 0 && newy >= 0 && newx < m && newy < n && !visited[newx][newy]) {
                    pq.push({cost + grid[newx][newy], {newx, newy}});
                }
            }
        }
        return -1;
    }
};
