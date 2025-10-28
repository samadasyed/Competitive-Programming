#include <bits/stdc++.h> 
using namespace std; 



int numIslands(vector<vector<char>>&grid) {

    if (grid.empty()) return 0; 

    int numOfIslands; 
    int r = 0, c = 0; 
    auto initial = grid[r][c];

    if (initial == 1) {
        numOfIslands++; 

        
    }

    auto right = grid[r][c+1]; 
    auto left = grid[r][c-1]; 
    auto up = grid [r-1][c];
    auto down = grid[r+1][c]; 

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