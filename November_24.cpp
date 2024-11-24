class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        long long negCount = 0;
        long long minNeg = INT_MAX;
        long long ans = 0;
        for(int i = 0;i<m;i++){
            for(int j= 0;j<n;j++){
                ans += abs(matrix[i][j]);
                minNeg = min(minNeg,(long long)abs(matrix[i][j]));
                if(matrix[i][j]<0){
                    negCount++;
                }
            }
        }
        return (negCount&1)?(ans-2*minNeg):ans;
    }
};