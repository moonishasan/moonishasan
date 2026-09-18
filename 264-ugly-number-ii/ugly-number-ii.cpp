class Solution {
public:
    bool isUgly(int n){
        while(n >= 1){
            if(n % 2 == 0){
                n /= 2;
            }
            else if(n % 3 == 0){
                n /= 3;
            }
            else if(n % 5 == 0){
                n /= 5;
            }
            else{
                break;
            }
        }
        if(n == 1){
            return true;
        }
        return false;
    }
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
         // First ugly number 
        ugly[0] = 1;
         // Three pointers
        int i2 = 0; 
        int i3 = 0; 
        int i5 = 0;
        for(int i = 1; i < n; i++){ // Generate the next possible ugly numbers 
            int next2 = ugly[i2] * 2;
            int next3 = ugly[i3] * 3;
            int next5 = ugly[i5] * 5;
            ugly[i] = min({next2, next3, next5});
            if(ugly[i] == next2){
                i2++;
            }
            if(ugly[i] == next3){
                i3++;
            }
            if(ugly[i] == next5){
                i5++; 
            }
        }
        return ugly[n-1];
    }
};