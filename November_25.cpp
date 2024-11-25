class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        string target = "123450";
        string start = "";
        int zeroPos = 0;

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 0) zeroPos = i * 3 + j;
                start += (board[i][j] + '0');
            }
        }

        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({start, zeroPos});
        visited.insert(start);
        int moves = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [curr, zero] = q.front();
                q.pop();

                if (curr == target) return moves;

                for (int neighbor : neighbors[zero]) {
                    string next = curr;
                    swap(next[zero], next[neighbor]);

                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push({next, neighbor});
                    }
                }
            }
            ++moves;
        }

        return -1;
    }
};
