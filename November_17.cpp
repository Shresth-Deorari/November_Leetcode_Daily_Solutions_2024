class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int> dq; // Monotonic deque to store indices
        int n = nums.size();
        vector<long long> prefix(n + 1, 0); // Prefix sums (1-based indexing)
        
        // Compute prefix sum
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        int minLength = INT_MAX;

        for (int i = 0; i <= n; ++i) {
            // Check if we can form a valid subarray
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                minLength = min(minLength, i - dq.front());
                dq.pop_front(); // Remove the smallest prefix index
            }
            
            // Maintain monotonicity: Remove indices with larger or equal prefix sums
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back();
            }
            
            // Add current index to the deque
            dq.push_back(i);
        }
        
        return (minLength == INT_MAX) ? -1 : minLength;
    }
};
