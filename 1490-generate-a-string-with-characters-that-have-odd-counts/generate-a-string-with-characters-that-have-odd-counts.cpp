class Solution {
public:
    string generateTheString(int n) {
        string ans = "";
        if(n == 1){
            return "a";       // or any character
        }
        if(n&1){  // odd
            for(int i = 1; i <= n-2; i++){
                ans += 'a';    // odd times
            }
            ans += 'b';     // odd time 
            ans += 'c';     // odd time
        }
        else{
            for(int i = 1; i <= n-1; i++){
                ans += 'a';     // odd times
            }
            ans += 'b';
        }
        return ans;
    }
};