class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int>ans(n,0);
        int xorr = 0;
        for(auto i : nums)xorr ^= i;
        for(int i = n-1;i>=1;i--){
            ans[n-i-1] = xorr^((1<<maximumBit) - 1);
            xorr ^= nums[i];
        }
        ans[n-1] = xorr^((1<<maximumBit) - 1);
        return ans;
    }
};