class Solution {
public:
    bool wordPattern(string pattern, string s) {  
        unordered_map<char, string> mpp1;
        unordered_map<string, char> mpp2;
        int i = 0;
        int j = 0;
        while (i < s.size()) {
            // No pattern character left
            if (j >= pattern.size()) {
                return false;
            }
            string word = "";
            // Extract one word
            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }
            char ch = pattern[j];
            // Check character -> word
            if (mpp1.find(ch) != mpp1.end()) {
                if (mpp1[ch] != word) {
                    return false;
                }
            }
            // Check word -> character
            if (mpp2.find(word) != mpp2.end()) {
                if (mpp2[word] != ch) {
                    return false;
                }
            }
            // Create mappings
            mpp1[ch] = word;
            mpp2[word] = ch;
            // Skip space
            if (i < s.size()) {
                i++;
            }
            j++;
        }
        // Number of words must equal number of pattern characters
        if (j != pattern.size()) {
            return false;
        }
        return true;
    }
};