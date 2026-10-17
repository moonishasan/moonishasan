class Solution {
public:
    int maxPower(string s) {
        int maxlen = 0;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            int len = 1;
            while(c == s[++i]){
                len++;
            }
            i--;
            maxlen = max(maxlen, len);
        }
        return maxlen;
    }
};