class Solution {
public:
    int minInsertions(string s) {
        int open = 0;  // no. of unmatched opening parenthesis
        int ans = 0;   // min no. of insertions needed
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                open++;
            }
            else{   // s[i] == ')'
                if(s[i+1] == ')'){
                    i++;
                }
                else{
                    ans++;
                }
                if(open > 0){
                    open--;
                }
                else{
                    ans++;
                }
            }
        }
        ans += 2*open;
        return ans;
    }
};