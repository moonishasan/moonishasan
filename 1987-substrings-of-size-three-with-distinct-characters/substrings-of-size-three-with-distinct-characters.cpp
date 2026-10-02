class Solution {
    bool isGood(string substr){
        if(substr[0] != substr[1] && substr[1] != substr[2] && substr[0] != substr[2]){
            return true;
        }
        return false;
    }
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        int l = 0;
        for(int r = 2; r < s.size(); r++){
            if(s[l] != s[l+1] && s[l] != s[l+2] && s[l+1] != s[l+2]){
                    count++;
            }
            l++;
        }
        return count;
    }
};