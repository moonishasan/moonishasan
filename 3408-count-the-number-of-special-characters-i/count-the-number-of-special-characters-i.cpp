class Solution {
public:
    int numberOfSpecialChars(string word) {
        int special = 0;
        unordered_set<char> s(word.begin(), word.end());
        for(char ch = 'a'; ch <= 'z'; ch++){
            if(s.count(ch) && s.count(toupper(ch))){
                special++;
            }
        }
        return special;
    }
};