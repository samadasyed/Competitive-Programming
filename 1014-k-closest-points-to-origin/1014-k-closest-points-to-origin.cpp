class Solution {
public:


struct CloserToOrigin {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        long long da = 1LL * a[0] * a[0] + 1LL * a[1] * a[1];
        long long db = 1LL * b[0] * b[0] + 1LL * b[1] * b[1];

        // for min-heap: return true when 'a' should come AFTER 'b'
        return da > db;  
    }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<vector<int>, vector<vector<int>>, CloserToOrigin> minHeap;

        for (auto &v : points) {
            minHeap.push({v[0], v[1]});
        }
        vector<vector<int>> ans; 

        for (int i = 0; i < k; i++) {
            ans.push_back(minHeap.top());
            minHeap.pop(); 
        }
        return ans; 


    }
};