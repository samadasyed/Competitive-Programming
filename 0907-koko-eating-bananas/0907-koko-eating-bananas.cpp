/**
{3, 6, 7, 11} and 8 hours to eat 

So in this case, at a eating speed of 4 bananas per hour, she can eat all the bananas here. Optimize for slowest eating speed that still gets through the bananas

Hour 1: 3 --> piles[0]
Hour 2 and 3: 6 --> 2 --> 0 piles[1]
Hour 4 and 5: 7 --> 3 --> piles [2]
Hour 6 7 8: 11 --> 7 --> 3 --> 0 piles[3]

Maybe have two cases: 

One where the hours >= piles.size() in which this problem becomes a "find the highest or second highest, or 3rd highest"

Case 2: Hours <= piles.size(). Then this becomes an optimization problem? 
Ideas: Sort the array, find the middle, and make that the hourly eating rate? Not sure if this work 
Ideas: Sort the array, temp = hours - array.size(), find the tempth highest and set that as your hourly rate. Adjust up until the tempth highest+1 rate, to find the slowest rate possible  


**/
class Solution {
public:
   int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // Calculate total hours needed at speed 'mid'
        long long totalHours = 0;
        for (int pile : piles) {
            totalHours += (pile + mid - 1) / mid; // Ceiling division
        }
        
        if (totalHours <= h) {
            right = mid; // Try smaller speed
        } else {
            left = mid + 1; // Need faster speed
        }
    }
    
    return left;
}
};