class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        if(n == 1){
            if(img1[0][0] == 1 && img2[0][0] == 1){
                return 1;
            }
            else{
                return 0;
            }
        }

        // 1. Store coordinates of 1s in img1
        // 2. Store coordinates of 1s in img2
        vector<pair<int, int>> img1_1s;
        vector<pair<int, int>> img2_1s;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1){
                    img1_1s.push_back({i, j});
                }
                if(img2[i][j] == 1){
                    img2_1s.push_back({i, j});
                }
            }
        }        
        // 3. For every 1 in img1
        //    For every 1 in img2
        //       calculate (dx, dy)
        map<pair<int,int>, int> freq;
        for(int i = 0; i < img1_1s.size(); i++){
            for(int j = 0; j < img2_1s.size(); j++){
                int dx = img2_1s[j].first - img1_1s[i].first;
                int dy = img2_1s[j].second - img1_1s[i].second;
                freq[{dx, dy}]++;
            }
        }
        int maxi = 0;
        for(auto it : freq){
            maxi = max(maxi, it.second);
        }
        return maxi;
    }
};