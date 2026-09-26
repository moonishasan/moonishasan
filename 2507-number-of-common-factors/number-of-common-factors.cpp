class Solution {
public:
    int commonFactors(int a, int b) {
        int count = 0;
        int smaller;
        if(a < b){
            smaller = a;
        }
        else{
            smaller = b;
        }
        for(int i = 1; i <= smaller; i++){
            if(a % i == 0 && b % i == 0){
                count++;
            }
        }
        return count;
    }
};