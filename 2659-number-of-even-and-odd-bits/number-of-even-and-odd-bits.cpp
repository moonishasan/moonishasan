class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0;
        int odd = 0;
        int currIndx = 0;
        while(n){
            if(n&1 && currIndx % 2 == 0){
                even++;
            }
            else if(n&1 && currIndx&1){
                odd++;
            }
            n >>= 1;
            currIndx++;
        }
        return {even, odd};
    }
};