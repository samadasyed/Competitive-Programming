#include <bits/stdc++.h> 

using namespace std; 

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //two pointers in the same direction
      int slow = 0; 
      for (int fast = 0; fast < nums.size(); fast++) {
        if (nums[fast] != 0){
            int slow_num = nums[slow]; //these three lines are a swap
            nums[slow] = nums[fast];
            nums[fast] = slow_num; 
            slow++; 
        }
      }
        
    }
};


int main () {
    return 0; 
}