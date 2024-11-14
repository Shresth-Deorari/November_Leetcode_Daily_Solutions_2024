class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = *max_element(quantities.begin(), quantities.end());
        while(low<=high){
            int mid = low + (high - low)/2;
            int i = 0, count = 0;
            vector<int>q(quantities.begin(),quantities.end());
            while(i<q.size()){
                count+= (q[i]+mid-1) / mid;
                i++;
            }
            if(count<=n){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};