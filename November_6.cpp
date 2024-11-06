class Solution {
    int findSetBits(int i) {
        int ans = 0;
        while (i) {
            ans += i & 1;
            i >>= 1;
        }
        return ans;
    }

public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedNums(nums.begin(), nums.end());
        sort(sortedNums.begin(), sortedNums.end());

        int start = 0;
        while (start < n) {
            int setBitsCount = findSetBits(nums[start]);
            int end = start;

            while (end < n && findSetBits(nums[end]) == setBitsCount) {
                ++end;
            }

            sort(nums.begin() + start, nums.begin() + end);

            start = end;
        }

        return nums == sortedNums;
    }
};
