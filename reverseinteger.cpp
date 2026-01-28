class Solution {
public:
    int reverse(int x) {
        vector<char> lol; 
        int xlength = to_string(abs(x)).length();
        string s = to_string(x);

        for (int i = xlength-1; i >= 0; i--){
            lol.push_back(s[i]); 
        }
        int y = 0;
        for (char c : lol) {
            y = y * 10 + (c - '0');
        }
        return y;
    }
};