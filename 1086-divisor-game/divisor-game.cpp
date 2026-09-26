class Solution {
    int turn = 1;
    int x = 0;
public:
    bool divisorGame(int n) {
        if(n == 1 && turn == 1){
            return false;
        }
        for(int i = 1; i < n; i++){
            if(n % i == 0){
                x = i;
                break;
            }
        }
        n = n - x;
        if(n == 1){
            if(turn % 2 != 0){
                return true;
            }
            else{
                return false;
            }
        }
        turn++;
        return divisorGame(n);
    }
};