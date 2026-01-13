class Solution {
public:
        vector<int> memory; 
        

    int minCostClimbingStairs(vector<int>& cost) {
        memory.resize(cost.size(), -1); //make the size of memory to be -1s of cost size
        if (cost.size() == 1) { 
            return cost[0]; 
        }
        if (cost.size() == 2) {
            return min(cost[0], cost[1]);  
        }
        return min(dfs(cost, 0), dfs(cost, 1));
    }

    int dfs(vector<int>& cost, int i) {
        if (i >= cost.size()) {
            return 0; 
        }
        if (memory[i] != -1) {
            return memory[i];
        }
        memory[i] = cost[i] + min(dfs(cost, i+1), dfs(cost, i+2));
        return memory[i];
    }
};