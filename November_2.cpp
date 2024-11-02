class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        if(sentence[0]!=sentence[n-1])return false;
        char last;
        for(int i = 0;i<n;i++){
            if(i<n-1 && sentence[i+1]==' '){
                last = sentence[i];
            }
            if(i<n-1 && sentence[i]==' '){
                if(sentence[i+1]!=last)return false;
            }
        }
        return true;
    }
};