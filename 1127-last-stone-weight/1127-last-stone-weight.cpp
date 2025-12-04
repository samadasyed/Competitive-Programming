class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap; 
        for (int i = 0; i < stones.size(); i++) {
            maxHeap.push(stones[i]); 
        }

        while (maxHeap.size() > 1) {
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top(); 
             
            if (x == y) {
                maxHeap.pop(); 
            }
            else {
                maxHeap.pop();
                y = y-x; 
                maxHeap.push(y); 
            }
        }
        maxHeap.push(0);
        return maxHeap.top(); 

    }
};