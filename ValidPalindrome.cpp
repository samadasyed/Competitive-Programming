class Solution {
public:
    bool isPalindrome(string s) {
        string clean = ""; 
        for (char c: s) {
            if (isalnum(c)) {
                clean.push_back(tolower(c)); 
            }
        }
        int right = clean.length()-1;
        int left = 0;
        while(left < right) {
            if (clean[left] != clean[right]){
                return false; 
            }
            left++; 
            right--; 
        }
        return true; 
    }
};