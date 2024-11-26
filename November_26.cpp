class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        if (n == 0) return -1; 
        vector<int> indegree(n, 0);

        for (auto& edge : edges) {
            if (edge[1] >= n || edge[0] >= n) return -1; 
            indegree[edge[1]]++;
        }

        int champion = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (champion != -1) return -1;
                champion = i;
            }
        }

        return champion;
    }
};
