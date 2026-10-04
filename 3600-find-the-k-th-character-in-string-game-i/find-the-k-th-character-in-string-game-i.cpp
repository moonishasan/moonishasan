class Solution {
public:
    string s = "a";
    char kthCharacter(int k) {
        string _new = "";
        for(char c : s){
            if(c == 'z'){
                _new.push_back('a');
            }
            _new.push_back(c+1);
        }
        s.append(_new);
        if(s.size() >= k){
            return s[k-1];
        }
        else{
            return kthCharacter(k);
        } 
    }
};