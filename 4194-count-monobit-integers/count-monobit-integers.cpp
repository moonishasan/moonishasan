class Solution {
private:
    bool isMonobit(int n){
        int zeroBits = 0;
        int setBits = 0;
        while(n){
            if(n&1){
                setBits++;
            }
            else{
                zeroBits++;
            }
            n = n >> 1;
        }
        if(setBits == 0 || zeroBits == 0){
            return true;
        }
        return false;
    }
public:
    int countMonobit(int n) {
        int ans = 0;
        for(int i = 0; i <= n; i++){
            if(isMonobit(i)){
                ans++;
            }
        }
        return ans;
    }
};