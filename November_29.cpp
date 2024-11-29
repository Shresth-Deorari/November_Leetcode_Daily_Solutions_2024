class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int m = grid.size(), n = grid[0].size();

        // If the starting path is blocked
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        // Priority queue (min-heap)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});

        // Time to reach each cell
        vector<vector<int>> timeToReach(m, vector<int>(n, INT_MAX));
        timeToReach[0][0] = 0;

        while (!pq.empty()) {
            auto [time, position] = pq.top();
            pq.pop();
            int x = position.first, y = position.second;

            // If we've reached the target
            if (x == m - 1 && y == n - 1) return time;

            // Explore neighbors
            for (auto dir : directions) {
                int newx = x + dir.first, newy = y + dir.second;
                if (newx >= 0 && newy >= 0 && newx < m && newy < n) {
                    int waitTime = max(0, grid[newx][newy] - time - 1);
                    if (waitTime % 2 != 0) waitTime++;  // Adjust to even wait time
                    int newTime = time + 1 + waitTime;

                    // Update if this path is better
                    if (newTime < timeToReach[newx][newy]) {
                        timeToReach[newx][newy] = newTime;
                        pq.push({newTime, {newx, newy}});
                    }
                }
            }
        }

        // If no path is found
        return -1;
    }
};
