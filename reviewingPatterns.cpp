#include <bits/stdc++.h> 

using namespace std; 


int vanillaBinarySearch(vector<int> nums, int target) {
        int left = 0; 
        int right = nums.size()-1; 

        while (left <= right) {
           int mid = left + (right - left)/2; 

           if (nums[mid] == target) {
            return mid; 
           }
           else if (nums[mid] > target) {
             right = mid - 1; 

           }
           else { //nums[mid] < target
             left = mid + 1; 
           }
           

        }
        return -1; 
}
//using number of islands as example for implementation.
int directions[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};  
int VanillaGridDFS(vector<vector<char>>& grid) {
    int rows = grid.size(); 
    int cols = grid[0].size(); 
    int islands = 0; 
    
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == '1') {
                gridDFS(grid, r, c);
                islands++; 
            }
        }
    }

}

void gridDFS(vector<vector<char>>& grid, int r, int c) {
    if (r < 0 || c < 0 || r > grid.size() || c > grid[0].size() || grid[r][c] == '0') {
        return; 
    }
    
    grid[r][c] = 0; 

    for (int i = 0; i < 4; i++) {
        gridDFS(grid, r+directions[i][0], c+directions[0][i]); 
    }
}








int main () {
    return 0; 
}