class Solution {
public:
    bool allCapital(string s){
        for(char c : s){
            if(c >= 'a' && c <= 'z'){
                return false;
            }
        }
        return true;
    }
    bool allSmall(string s){
        for(char c : s){
            if(c >= 'A' && c <= 'Z'){
                return false;   
            }
        }
        return true;
    }
    bool firstCap(string s){
        if(s[0] >= 'a' && s[0] <= 'z'){
            return false;
        }
        for(int i = 1; i < s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                return false;
            }
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        if(allCapital(word) || allSmall(word) || firstCap(word)){
            return true;
        }
        return false;
    }
};