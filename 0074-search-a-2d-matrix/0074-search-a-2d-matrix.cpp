class Solution {
public:

    bool binarySearch(const vector<int>& selectedArray, int target)  { // might change selected array parameter later if don't have to copy it 
        int left = 0; 
        int right = selectedArray.size()-1; 

        while (left <= right) {
            int mid = left + (right - left) /2; 

            if (selectedArray[mid] == target) {
                return true; 
            }
            else if (selectedArray[mid] < target){
                left = mid + 1; 
            }
            else { //selectedArray[mid] > target
                right = mid - 1; 
            }

        }
        return false; 
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     //check upper bound of each array within the vector, so in example 1 that's 3 arrays, and 7, 20, and 60 
     //if target > that upper bound (ie 7, 20, and 60) that means we can ignore the rest of the arrays and narrow down
     //if it's in the array in which target is greater than the upper bound
     //do binary search of that array
     for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][matrix[0].size()-1] >= target) { 
            return binarySearch(matrix[i], target);
        }
     }   
     return false;
    }
};