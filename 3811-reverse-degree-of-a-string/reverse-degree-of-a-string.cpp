class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        int i = 1;
        // 26 + 'a' - ch
        for(char c : s){
            ans += (26 + 'a' - c) * i;
            i++;
        }
        return ans;
    }
};