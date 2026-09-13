class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        for(char c : s){
            freq[c]++;
        }
        int maxi = INT_MIN;  // odd
        int mini = INT_MAX;  // even
        for(auto it : freq){
            if(it.second % 2 != 0){  // max odd freq
                maxi = max(maxi, it.second);
                continue;
            }
            if(it.second % 2 == 0){   // min even freq
                mini = min(mini, it.second);
                continue;
            }
        }
        int diff = maxi - mini;
        return diff;
    }
};