class Solution {
public:                            
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        for(char c : t){
            need[c]++;
        }
        unordered_map<char, int> window;
        int start = 0;
        int minLen = INT_MAX;
        int count = 0;  // how many required characters we currently have
        int left = 0;
        for(int right = 0; right < s.size(); right++){
            char c = s[right];
            window[c]++;
            if(need.count(c) && window[c] <= need[c]){
                count++;
            }
            while(count == t.size()){
                // update answer if this window is smaller
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }
                char removeChar = s[left];
                window[removeChar]--;
                // If removing it makes us deficient,
                // the window is no longer valid
                if(need.count(removeChar) && window[removeChar] < need[removeChar]) {
                    count--;
                }
                left++;
            }
        }
        if(minLen == INT_MAX){
            return "";
        }
        return s.substr(start, minLen);
    }
};