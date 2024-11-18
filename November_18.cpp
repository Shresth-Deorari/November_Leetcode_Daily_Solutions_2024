class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(!k){
            vector<int>ans(code.size(),0);
            return ans;
        }
        vector<int>temp(code.begin(), code.end());
        temp.insert(temp.end(),code.begin(),code.end());
        for(int i = 1;i<temp.size();i++){
            temp[i] += temp[i-1];
        }
        if(k<0){
            for(int i = code.size()-1;i<2*code.size()-1;i++){
                code[i-code.size()+1] = abs(temp[i] - temp[i+k]);
            }
        }
        else{
            for(int i = 0;i<code.size();i++){
                code[i] = abs(temp[i] - temp[i+k]);
            }
        }
        return code;
    }
};