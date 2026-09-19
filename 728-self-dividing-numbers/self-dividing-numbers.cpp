class Solution {
public:
    bool isSelfDividing(int n){
        string st = to_string(n);
        for(char c : st){
            if(c == '0'){
                return false;
            }
            else if(n % (c-'0') != 0){
                return false;
            }
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right){
        vector<int> ans;
        for(int i = left; i <= right; i++){
            if(isSelfDividing(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};