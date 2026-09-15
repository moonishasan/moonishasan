class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        // start = first index from where we are allowed to select our next palindrome. This prevents overlapping substrings.
        // ans = number of palindromic substrings we have selected
        int ans = 0;
        int start = 0;
        // Lambda function to check whether s[l...r] is a palindrome
        auto check = [&](int l, int r) {
            while (l < r) {
                if (s[l++] != s[r--]) {
                    return false;
                }
            }
            return true;
        };
        for(int r = k - 1; r < n; r++){
            int l = r - k + 1;
            if (l >= start && check(l, r)) {
                ans++;
                start = r + 1;
                continue;
            }
            // If length k didn't work, check length k+1.
            l = r - k;
            if (l >= start && check(l, r)) {
                ans++;
                start = r + 1;
            }
        }
        return ans;
    }
};