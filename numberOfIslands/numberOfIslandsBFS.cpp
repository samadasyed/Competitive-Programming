#include <bits/stdc++.h>

    using namespace std; 
    int directions [4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; 

    int numIslands(vector<vector<char>>& grid) { //doesn't change between this and DFS
        int rows = grid.size(); 
        int cols = grid[0].size(); 
        int islands = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    bfs(grid, r, c);
                    islands++; 
                }
            }
        }
        return islands; 
    }

    void bfs(vector<vector<char>>& grid, int r, int c) {
        queue<pair<int,int>> q; 
        grid[r][c] = '0';
        q.push({r, c}); 

        while (!q.empty()) {
            auto node = q.front(); 
            q.pop(); 
            int ROW = node.first; 
            int COL = node.second;
            for (int i = 0; i < 4; i++) {
                int nr = ROW + directions[i][0]; 
                int nc = COL + directions[i][1]; 
                if (nr >= 0 && nc >= 0 && nr < grid.size() &&
                    nc < grid[0].size() && grid[nr][nc] == '1') {
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
            
            
        }
    }




    int main () {

    vector<vector<char>> gridExample1 = {
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}
    }; 


    vector<vector<char>> gridExample2 = {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}
    }; 

        return 0; 
    }