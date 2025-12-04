class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap; 

        for (int s : nums) {
            maxHeap.push(s); 
        }
        for (int i = 1; i < k; i++) {
            maxHeap.pop();
        }
        return maxHeap.top(); 
    }
};