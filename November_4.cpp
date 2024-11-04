class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int repeat = 1;
        for(int i = 0;i<word.size()-1;i++){
            if(word[i]==word[i+1] && repeat<9){
                repeat++;
            }
            else{
                ans+= to_string(repeat);
                ans+=word[i];
                repeat = 1;
            }
        }
        ans+= to_string(repeat);
        ans+=word[word.size()-1];
        return ans;
    }
};