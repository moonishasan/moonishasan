class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> freq;
        for(char c : t){
            freq[c]++;
        } 
        for(char c : s){
            freq[c]--;
        }
        for(auto it : freq){
            if(it.second == 1){
                return it.first;
            }
        }
        return '-1';
    }
};