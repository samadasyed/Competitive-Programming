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
int multiSourceBFSGrid(vector<vector<int>>& grid) {
    int rows = grid.size(); 
    int cols = grid[0].size(); 

    queue<pair<int,int>> q; 
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < rows; c++) {
            if (grid[r][c] == 0) {
                multiSourceBFS(grid, r, c, q); 
            }
        }
    }
}

void multiSourceBFS(vector<vector<int>>& grid, int r, int c, queue<pair<int,int>> q) {
    q.push({r,c}); 

    while (!q.empty()) {
        auto node = q.front(); 
        q.pop(); 

        int row = node.first; 
        int col = node.second; 

        for (int i = 0; i < 4; i++) {
            int r = row + directions[i][0];
            int c = col + directions[i][1]; 

             if (r < 0 || r >= grid.size() || c < 0 ||
                    c >= grid[0].size() || grid[r][c] != INT_MAX) {
                    continue;
                }

                grid[r][c] = grid[row][col] + 1;
                q.push({r, c});
        }
    }
}


//1D DP (Which is kinda a bit like backtracking)
//Using House Robber as first example 

    int oneDDP(vector<int>& nums) {
        vector<int> dpArr (nums.size()+2, -1); //creating a memory of 2 more than the nums array
        for (int i = nums.size()-1; i >= 0; i--) {
            if (i = -1) {
                break; 
            }
            dpArr[i] = max(dpArr[i+2] + nums[i], dpArr[i+1]);  //trying to find the max money generated from skipping (dpArr[i+1]) and from robbing and going to the next dpArr[i+2] + nums[i]; 
        } 
        return dpArr[0]; 
    }


int main () {
    return 0; 
}