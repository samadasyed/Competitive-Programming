class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int maxSub = 0; 
    int left = 0; 
    int right = 0; 
    unordered_map<char, int> freq; 
    if (s.length() == 0) return 0; 
    if (s.length() == 1) return 1; 

    while (right < s.length()) {
        char c = s[right]; 
        freq[c]++; 
        right++; 

        while (freq[c] > 1){
            freq[s[left]]--;
            left++; 
        }
        maxSub = max(maxSub, right-left); 
    }
    return maxSub; 
    }
};