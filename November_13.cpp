class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i = 0;i<nums.size()-1;i++){
            long long low = i+1, high =nums.size()-1;
            long long left =-1,right = -1;
            while(low<=high){
                long long mid = low + (high-low)/2;
                if(nums[i] + nums[mid]<=upper){
                    right = mid;
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            low = i+1, high = nums.size()-1;
            while(low<=high){
                long long mid = low + (high-low)/2;
                if(nums[i] + nums[mid]>=lower){
                    left = mid;
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            if(left==-1 || right==-1)continue;
            ans += right-left+1;
        }
        return ans;
    }
};