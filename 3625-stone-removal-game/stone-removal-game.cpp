class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10){
            return false;
        }
        int x = 10; // no of stones to be removed
        int turn = 1;
        while(n != 0){
            if(turn % 2 != 0){  // alice turn
                if(n - x < 0){
                    return false;
                }
                n = n - x;
                x--;
                if(n == 0){
                    return true;
                }
                turn++;
            }
            else{   // bob turn
                if(n - x < 0){
                    return true;
                }
                n = n - x;
                x--;
                if(n == 0){
                    return false;
                }
                turn++;
            }
        }
        return true;
    }
};