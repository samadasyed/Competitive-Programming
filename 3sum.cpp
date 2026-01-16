class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> temp; 
        vector<vector<int>> res; 
        sort(nums.begin(), nums.end()); 
        
        for (int i = 0; i < nums.size(); i++) {
        //removes duplicates
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i+1;
        int right = nums.size()-1; 
            while (right > left) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++; 
                }
                else    
                    {
                     temp.push_back(nums[left]);
                     temp.push_back(nums[i]); 
                     temp.push_back(nums[right]); 
                     res.push_back(temp); 
                     temp.clear();
                     left++;
                     right--;
                     while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
            }
        }
        return res;
    }
};