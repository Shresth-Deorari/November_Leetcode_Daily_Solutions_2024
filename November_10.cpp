class Solution {
private:
    void countAndStoreBits(int x, vector<int>& bitCount) {
        for (int i = 0; i < 32; i++) {
            bitCount[i] += (x & (1 << i)) ? 1 : 0;
        }
    }

    void removeBits(int x, vector<int>& bitCount, int& orOfWindow) {
        for (int i = 0; i < 32; i++) {
            if (x & (1 << i)) {
                if (--bitCount[i] == 0) {
                    orOfWindow &= ~(1 << i);
                }
            }
        }
    }

public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (!k) return 1;

        int left = 0, right = 0;
        int ans = INT_MAX;
        int orOfWindow = 0;
        vector<int> bitCount(32, 0);

        while (right < nums.size()) {
            countAndStoreBits(nums[right], bitCount);
            orOfWindow |= nums[right];
            while (orOfWindow >= k) {
                ans = min(ans, right - left + 1);
                removeBits(nums[left], bitCount, orOfWindow);
                left++;
            }
            right++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
