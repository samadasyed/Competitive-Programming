#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    string input; 
    cin >> input;
    stringstream ss(input);
    char ch; 
    vector<int> arr;
    int a; 
    while (ss >> a) {
        arr.push_back(a);
        ss >> ch; 
        
    }
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << endl; 
    }
    return 0;
}
