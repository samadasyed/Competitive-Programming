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
int VanillaGridDFS(int); 








int main () {
    return 0; 
}