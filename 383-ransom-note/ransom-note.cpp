class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {0};
        for(char c : magazine){
            freq[c-'a']++;
        }
        for(int i = 0; i < ransomNote.size(); i++){
            // if the char that exist in ransomNote does not exist in magazine
            if(freq[ransomNote[i]-'a'] == 0){
                return false;
            }
            // else if that character exists 
            else if(freq[ransomNote[i]-'a'] > 0){
                freq[ransomNote[i]-'a']--;
            }
        }
        return true;
    }
};