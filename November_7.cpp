class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int>bitFrequency(32,0);
        int maxi = 0;
        for(auto it : candidates){
            int temp = it;
            int i = 0;
            while(temp){
                bitFrequency[i] += (temp)&1;
                maxi = max(maxi, bitFrequency[i++]);
                temp = temp>>1;
            }
        }
        return maxi;
    }
};