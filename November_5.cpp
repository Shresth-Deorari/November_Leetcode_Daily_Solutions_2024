class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            if(i==s.size()-1)break;
            if(s[i]==s[++i]){
                continue;
            }
            ans++;
        }
        return ans;
    }
};