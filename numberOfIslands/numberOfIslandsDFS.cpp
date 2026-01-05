#include <bits/stdc++.h> 
using namespace std; 

    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; //up, down, right, left

    int numIslands(vector<vector<char>>&grid) {
        int rows = grid.size(); 
        int cols = grid[0].size(); 
        int islands = 0; 

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (grid[r][c] == '1') {
                    dfs(grid, r, c);
                    islands++; 
                }
            }
        }
    return islands; 

    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0') {
            return; 
        }
        
        grid[r][c] = '0'; 

        for (int i = 0; i < 4; i++) { //sending our dfs in all 4 directions 
            dfs (grid, r + directions[i][0], c + directions[i][1]); 
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