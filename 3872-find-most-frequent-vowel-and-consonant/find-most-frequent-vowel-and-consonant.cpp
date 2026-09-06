class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq_vowels;
        unordered_map<char, int> freq_cons;
        for(char c : s){
            if(c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u'){
                freq_vowels[c]++;
            }
            else{
                freq_cons[c]++;
            }
        }
        int maxi = 0;
        int maxi_ = 0;
        for(auto it : freq_vowels){
            maxi = max(maxi, it.second);
        }
        for(auto it : freq_cons){
            maxi_ = max(maxi_, it.second);
        }
        return maxi + maxi_;
    }
};