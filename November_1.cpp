class Solution {
public:
    string makeFancyString(string s) {
        string temp;
        int freq = 1;
        for(int i = 0;i<s.size();i++){
            if(i>0 && s[i]==s[i-1])freq++;
            else freq = 1;
            if(freq<3)temp+=s[i];
        }
        return temp;
    }
};