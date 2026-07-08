#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> arr; 
    int x; 
    cin >> x; 
    for (int i = 0; i < x; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    for (int i = arr.size()-1; i >= 0; i--) {
        cout << arr[i] << " ";    
    } 
    
}
