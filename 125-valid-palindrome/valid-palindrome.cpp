class Solution {
public:
    char to_lowerCase(char c){
        if(c >= 'A' && c <= 'Z'){
            return c-'A'+'a';
        }
        return c;
    }
    bool is_alphaNumeric(char c){
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s){
        int st = 0;
        int end = s.size()-1;
        while(st <= end){
            if(!is_alphaNumeric(s[st])){
                st++;
            }
            else if(!is_alphaNumeric(s[end])){
                end--;
            }
            else{
                if(to_lowerCase(s[st]) != to_lowerCase(s[end])){
                    return false;
                }
                st++;
                end--;
            }
        }
        return true;
    }
};