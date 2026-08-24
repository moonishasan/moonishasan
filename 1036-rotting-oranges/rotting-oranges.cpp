class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n == 1 && m == 1 && grid[0][0] == 0){
            return 0;
        }
        // int time= 0;
        queue<pair<int, int>> q;
        int fresh = 0;
        // put all rotten oranges in queue
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0 && q.empty()){
            return 0;
        }
        // while(!q.empty() && fresh > 0){
        //     int size = q.size();
        //     for(int i = 0; i < size; i++){
        //         pair<int,int> curr = q.front();
        //         if(grid[curr.first+1][curr.second] == 1){
        //             q.push({curr.first+1, curr.second});
        //             fresh--;
        //         }
        //         else if(grid[curr.first][curr.second+1] == 1){
        //             q.push({curr.first, curr.second+1});
        //             fresh--;
        //         }
        //         time++;
        //         q.pop();
        //     }
        // }

        // return time;
        int time = -1;
        // int count = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto top  = q.front();
                q.pop();
                int dir[] = {-1,0,1,0,-1};
                for(int j = 0; j < 4; j++){
                    int dRow = top.first + dir[j];
                    int dCol = top.second + dir[j+1];
                    if(dRow >= 0 && dRow < grid.size() && dCol >=0  && dCol < grid[0].size() && grid[dRow][dCol] == 1){
                        q.push({dRow,dCol});
                        fresh--;
                        grid[dRow][dCol] = 2;
                    }
                }
            }    
            time++;
        } 
        if(fresh == 0){
            return time;
        }
        return -1;
    }
};