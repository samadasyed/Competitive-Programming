class HitCounter {
public:
    vector<int> timestamps; 
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        timestamps.push_back(timestamp); 
    }
    
    int getHits(int timestamp) {
      auto startIterator = lower_bound(timestamps.begin(), timestamps.end(),timestamp - 300 + 1); 
       return timestamps.end() - startIterator;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */