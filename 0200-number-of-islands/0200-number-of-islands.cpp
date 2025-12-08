class Solution {
    int directions[4][2] = {{1, 0}, {-1,0}, {0, 1}, {0, -1}}; //down, up, right, left
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(); //.size() of a 2D grid returns the number of rows (counts number of arrays in the array)
        int cols = grid[0].size(); // takes the first array and counts number of items, aka columns
        int islands = 0; 

        for (int r = 0; r < rows; r++) { //represents each rows
            for (int c = 0; c < cols; c++) { //the loop inside represents the columns per row, so one iteration 
            //goes from grid[0][0], grid[0][1], grid[0][2], etc. 
                if (grid[r][c] == '1') {
                    dfs(grid, r, c);
                    islands++; 
                }
            }
        }
        return islands; 
    }

    void dfs(vector<vector<char>>& grid, int r, int c) { //passing the actual grid reference so we modify the grid
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0') {
            return; 
        } //this whole sequence is for bounds checking, ie error handling + returning when hit a wall/no islands

        grid[r][c] = '0'; //transforming the 1 we found to a zero so we don't hit it again
        for (int i = 0; i < 4; i++) { //doing a dfs in all 4 directions
            dfs (grid, r + directions[i][0], c + directions[i][1]); 
        }
    }

};