#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream> 
using namespace std;


int main() {
    int numArr, numOfQ; 
    cin >> numArr >> numOfQ; 
    vector<vector<int>> arr; 
    cin.ignore();
    for (int i = 0; i < numArr; i++){
        vector<int> vec;
        int k; 
        cin >> k; 
        for (int j = 0; j < k; j++){
            int x; 
            cin >> x; 
            vec.push_back(x);
        }
        arr.push_back(vec); 
    }
    for (int i= 0; i < numOfQ; i++){
        int x, y; 
        cin >> x >> y; 
        cout << arr[x][y] << endl;
    }
    return 0;
}
