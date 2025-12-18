
//format I went with: length + # + word 
//5#hello5#world
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
            int j = s.find('#', i); //find our first #, set to J
            int length = stoi(s.substr(i, j-i)); //find the length of our actual string (ie number before #)
            string str = s.substr(j+1, length); //grab our string
            res.push_back(str);
            i = j + 1 + length; //move to next word

        }
        return res; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

