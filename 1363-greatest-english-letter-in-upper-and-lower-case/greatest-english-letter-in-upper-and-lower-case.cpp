class Solution {
public:
    string greatestLetter(string s) {
        unordered_map<char, int> freq;
        for(char c : s){
            freq[c]++;
        }
        sort(s.begin(), s.end());
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            char u = toupper(s[i]);
            char l = tolower(s[i]);
            if(freq[u] > 0 && freq[l] > 0){
                ans = u;
            }
        }
        return ans;
    }
};