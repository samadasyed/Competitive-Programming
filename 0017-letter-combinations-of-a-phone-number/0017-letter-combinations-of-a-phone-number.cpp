/**

What I'm thinking so far, we're given a string of numbers, so I want to take each number and convert it a string of possibilies

Then I want to take that and build our backtracking tree



**/

class Solution {
public:
    
    const unordered_map<char, string> keyboard = {

    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},

    };


    void dfs(vector<string>& res, vector<char>& path, string digits, int i) {
        if (path.size() == digits.size()) {
            string s(path.begin(),path.end()); 
            res.emplace_back(s);
            return;
        }
        for (char c : keyboard.at(digits[i])) {
            path.emplace_back(c);
            dfs(res,path,digits,i+1);
            path.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
    vector<string> res;
    vector<char> path; 
    dfs(res, path, digits, 0);
    return res; 
    }
};