/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int n; 

    bool is_celebrity (int i) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue; 
            if (knows(i, j) || !knows(j, i)) {
                return false; 
            }
        }
        return true; 
    }
    int findCelebrity(int n) {
        this->n = n; 

        int celebrity_candidate = 0; 

        for (int i = 1; i < n; i++) {
            if (knows(celebrity_candidate, i)) {
                celebrity_candidate = i; 
            }
        }
        if (is_celebrity(celebrity_candidate)) {
            return celebrity_candidate; 
        }
        return -1; 
    }
};