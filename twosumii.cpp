#include <bits/stdc++.h> 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s = 0; 
        int b = numbers.size()-1;

        while (s < b) {
            int two_sum = numbers[s] + numbers[b];
            if (two_sum > target){
                b--; 
            }

            if (two_sum < target){ 
                s++; 
            }
            if (two_sum == target) {
                return {s+1,b+1}; 
            }
        }
        return {};
    }
};