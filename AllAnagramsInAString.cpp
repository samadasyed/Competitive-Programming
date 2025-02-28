class Solution {
public:
    bool IsAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        for (char c : t) count[c - 'a']--;

        for (int n : count) {
            if (n != 0) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int window = p.size();
        int left = 0;
        int right = window;
        vector<int> ans;

        while (right <= s.size()) {
            if (IsAnagram(s.substr(left, window), p)) {
                ans.push_back(left);
            }
            left++;
            right++;
        }
        return ans;
    }
};
