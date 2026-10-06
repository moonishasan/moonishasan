class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int moves = 0;
        for(char c : s){
            if(c == '('){
                open++;
            }
            else if(c == ')' && open > 0){
                open--;
            }
            else if(c == ')' && open == 0){
                moves++;
            }
            
        }
        return open + moves;
    }
};