class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        int i = 1;
        for(char c : s){
            int prod = i * (26-(c-'a'));
            ans += prod;
            i++;
        }
        return ans;
    }
};