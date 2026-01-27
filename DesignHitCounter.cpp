class HitCounter {
public:
    vector<int> timestampsHit; 
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        timestampsHit.push_back(timestamp); 
    }
    
    int getHits(int timestamp) {
        if (timestampsHit.size() == 0) {
            return 0; 
        }
        int left = 0; 
        int right = timestampsHit.size()-1; 
        int mid = -1; 
        while (left <= right){
            mid = left + (right-left)/2; 

            if (timestampsHit[mid] > timestamp) {
                right = mid -1; 
            }
            else  {
                left = mid + 1;
            }
        }
        return (timestampsHit[mid]);  
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */