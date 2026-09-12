class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // last bit should be 1 always
        int cnt_of_one = 0;
        for(char c : s){
            if(c == '1'){
                cnt_of_one++;
            }
        }
        if(cnt_of_one == 1){
            s[s.size()-1] = '1';
            for(int i = 0; i < s.size()-1; i++){
                s[i] = '0';
            }
            return s;
        }
        else{
            for(int i = 0; i < cnt_of_one-1; i++){
                s[i] = '1';
            }
            s[s.size()-1] = '1';
            for(int i = cnt_of_one-1; i < s.size()-1; i++){
                s[i] = '0';
            }
        }
        return s;
    }
};