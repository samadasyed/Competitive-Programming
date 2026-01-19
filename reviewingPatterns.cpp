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

int VanillaGridBFS(vector<vector<char>>& grid) {
    int rows = grid.size(); 
    int cols = grid[0].size(); 
    int islands = 0; 

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == '1') {
                gridBFS(grid, r, c); 
                islands++; 
            }
        }
    }
}

void gridBFS(vector<vector<char>>& grid, int r, int c) {
    queue<pair<int, int>> q;
    grid[r][c] = '0'; 
    q.push({r, c}); 
    while (!q.empty()) {
        auto node = q.front(); 
        q.pop(); 
        int row = node.first; 
        int col = node.second;
        
        for (int i = 0; i < 4; i++) { //review this
            int nr = row + directions[i][0]; 
            int nc = col + directions[i][1]; 
            if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == '1') {
                q.push({nr, nc}); 
                grid[nr][nc] == '0'; 
            }
        }
    }
}

//using walls and gates
int multiSourceBFS(vector<vector<int>>& grid) {

}



int main () {
    return 0; 
}