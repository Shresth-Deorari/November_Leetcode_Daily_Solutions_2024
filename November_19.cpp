class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        long long sum = 0;
        unordered_map<int,int>mp;
        for(int i = 0;i<k;i++){
            sum+= nums[i];
            mp[nums[i]]++;
        }
        for(int i = k;i<n; i++){
            if(mp.size()==k)ans = max(ans,sum);
            sum-= nums[i-k];
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0)mp.erase(nums[i-k]);
            sum+= nums[i];
            mp[nums[i]]++;
        }
        if(mp.size()==k)ans = max(ans,sum);
        return ans;
    }
};