class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;
        for(char c : magazine){
            freq[c]++;
        }
        for(int i = 0; i < ransomNote.size(); i++){
            // if the char that exist in ransomNote does not exist in magazine
            if(freq[ransomNote[i]] == 0){
                return false;
            }
            // else if that character exists 
            else if(freq.count(ransomNote[i])){
                freq[ransomNote[i]]--;
            }
        }
        return true;
    }
};