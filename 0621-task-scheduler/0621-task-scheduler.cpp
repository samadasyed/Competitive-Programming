class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

    unordered_map<char, int> freq;
    for (char task : tasks) freq[task]++;

    priority_queue<int> maxHeap;
    for (auto& [task, count] : freq) {
        maxHeap.push(count);
    }
    
    int time = 0;
    while (!maxHeap.empty()) {
        vector<int> temp;
        
        for (int i = 0; i <= n; i++) {
            if (!maxHeap.empty()) {
                int count = maxHeap.top();
                maxHeap.pop();
                if (count > 1) {
                    temp.push_back(count - 1);
                }
                time++;
            }
            else {
                if (!temp.empty()) {
                    time++;
                }
            }
        }
        
        for (int count : temp) {
            maxHeap.push(count);
        }
    }
    
    return time;
}
};

/**
if (res[res.size()-1] == maxHeap.top() && counter == 0) {
                if (rejects.size() != 0) {
                    res.push_back(rejects.top()); 
                    rejects.pop(); 
                }
                else {
                    res.push_back(maxHeap.top());
                    maxHeap.pop(); 
                }

            }
**/