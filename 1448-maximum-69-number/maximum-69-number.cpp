class Solution {
public:
    int maximum69Number (int num) {
        string _num = to_string(num);
        for(char& d : _num){
            if(d == '6'){
                d = '9';
                break;
            }
        }
        int ans = stoi(_num);
        return ans;
    }
};