class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = ""; 
        for (int i = 0; i < strs.size(); i++) {
            res += to_string(strs[i].length());
            res += "#"; 
            res += strs[i]; 
        }
        return res; 
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res; 
        int i = 0; 

        while (i < s.size()) {
            int j = s.find('#', i);
            int length = stoi(s.substr(i, j-i)); 
            string str = s.substr(j+1, length); 
            res.push_back(str);
            i = j + 1 + length; 

        }
        return res; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

/**our encode method I'm going to take the string and encode it like

input = [hello, hi, bye]

hello;hi;bye



**/