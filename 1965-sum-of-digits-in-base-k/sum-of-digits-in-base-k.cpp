class Solution {
private: 
    int digitSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
public:
    int sumBase(int n, int k) {
        if(n == 10){
            return digitSum(n);
        }
        int num = 0;
        while(n > 0){
            int d = n % k;
            num = num * 10 + d;
            n /= k;
        }
        // int rev_num = 0;
        // while(num != 0){
        //     rev_num = rev_num * 10 + (num % 10);
        //     num /= 10;
        // }
        return digitSum(num);
    }
};