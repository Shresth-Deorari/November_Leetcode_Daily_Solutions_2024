class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        bool isValid = true; 

        for (int i = 1; i < k; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            ans.push_back(nums[k - 1]); 
        } else {
            ans.push_back(-1);
        }

        for (int i = k; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                isValid = false;
            }

            if (nums[i - k + 1] != nums[i - k] + 1) {
                isValid = true;
                for (int j = i - k + 2; j <= i; j++) {
                    if (nums[j] != nums[j - 1] + 1) {
                        isValid = false;
                        break;
                    }
                }
            }

            if (isValid) {
                ans.push_back(nums[i]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
