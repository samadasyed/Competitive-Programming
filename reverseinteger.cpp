class Solution {
public:
    int reverse(int x) {
        int original = x; 
        if (x == -2147483648) {
            return 0; 
        }
        x = abs(x); 
        string s = to_string(x); 
        std::reverse(s.begin(), s.end()); 
        long long res = stoll(s);
        if (original < 0) {
              res *= -1;
        }
        if (res < -(1LL << 31) || res > (1LL << 31) - 1) {
            return 0;
        }
        return static_cast<int>(res);
    }
};