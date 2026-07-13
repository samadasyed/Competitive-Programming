#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b; 
    cin >> a; 
    cin >> b; 
    cout << a.size() << " "; 
    cout << b.size() << endl; 
    cout << a + b << endl; 
    string c = a; 
    c[0] = b[0]; 
    string d = b; 
    d[0] = a[0];
    cout << c << " ";
    cout << d << endl; 
    
  
    return 0;
}//https://www.hackerrank.com/challenges/c-tutorial-strings/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign
