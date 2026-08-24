class Solution {
public:
    bool checkPalindrome(string s){
        int st = 0;
        int end = s.size()-1;
        while(st < end){
            if(s[st] != s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto word : words){
            if(checkPalindrome(word)){
                return word;
            }
        }
        return "";
    }
};