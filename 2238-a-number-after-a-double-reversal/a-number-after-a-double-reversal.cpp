class Solution {
public:
    int reverseNum(int n){
        int rev = 0;
        while(n){
            int d = n % 10;
            rev = rev * 10 + d;
            n /= 10;
        }
        return rev;
    }
    bool isSameAfterReversals(int num) {
        int reversed1 = reverseNum(num);
        int reversed2 = reverseNum(reversed1);
        if(num == reversed2){
            return true;
        }
        return false;
    }
};