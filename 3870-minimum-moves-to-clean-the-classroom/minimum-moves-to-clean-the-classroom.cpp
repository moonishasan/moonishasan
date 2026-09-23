class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        // Give every litter cell a unique bit number
        vector<vector<int>> litterID(m, vector<int>(n, -1));
        int startRow = 0;
        int startCol = 0;
        int litterCount = 0;
        // Find S and assign IDs to every L
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(classroom[i][j] == 'S') {
                    startRow = i;
                    startCol = j;
                }

                else if(classroom[i][j] == 'L') {
                    litterID[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        // No litter to collect
        if(litterCount == 0) {
            return 0;
        }

        // All litter initially uncollected
        int startMask = (1 << litterCount) - 1;

        /*
            visited[row][col][energy][mask]

            mask tells us which litter is still uncollected.
        */
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        // row, col, remaining energy, mask
        queue<array<int, 4>> q;

        q.push({startRow, startCol, energy, startMask});

        visited[startRow][startCol][energy][startMask] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {

            int size = q.size();

            // Process one BFS level
            while(size--) {

                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if(mask == 0) {
                    return moves;
                }

                // No energy means we cannot move
                if(currEnergy == 0) {
                    continue;
                }

                // Try all 4 directions
                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Outside grid
                    if(nr < 0 || nr >= m || nc < 0 || nc >= n) {
                        continue;
                    }

                    // Wall
                    if(classroom[nr][nc] == 'X') {
                        continue;
                    }

                    int nextEnergy;
                    int nextMask = mask;

                    // Moving to a cell normally costs 1 energy
                    nextEnergy = currEnergy - 1;

                    // If we reach R, energy becomes full
                    if(classroom[nr][nc] == 'R') {
                        nextEnergy = energy;
                    }

                    // If this cell contains litter
                    if(classroom[nr][nc] == 'L') {

                        int id = litterID[nr][nc];

                        // Mark this litter as collected
                        nextMask &= ~(1 << id);
                    }

                    // Have we already visited this exact state?
                    if(!visited[nr][nc][nextEnergy][nextMask]) {

                        visited[nr][nc][nextEnergy][nextMask] = true;

                        q.push({
                            nr,
                            nc,
                            nextEnergy,
                            nextMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};