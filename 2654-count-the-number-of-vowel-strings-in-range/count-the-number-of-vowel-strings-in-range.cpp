class Solution {
public:
    bool is_vowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        while(left <= right){
            string s = words[left];         
            if(is_vowel(s[0]) && is_vowel(s[s.size()-1])){
                count++;
            }
            left++;
        }
        return count;
    }
};