class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n);
        for(int i = 0; i < n; i++){
            perm[i] = i;
        }
        vector<int> original = perm;
        int opt = 0;
        vector<int> arr(n);
        do{
            for(int i = 0; i < n; i++){
                if(i % 2 == 0){
                    arr[i] = perm[i / 2];
                } 
                else{
                    arr[i] = perm[n/2 + (i-1)/2];
                }
            }
            opt++;
            perm = arr;
        }while(perm != original);
        return opt;
    }
};