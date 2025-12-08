class MyStack {
public:

queue<int> myQueue; 

    MyStack() {
        
    }
    
    void push(int x) {
        myQueue.push(x);
        for (int i = 1; i < myQueue.size(); i++) {
            int y = myQueue.front(); 
            myQueue.pop(); 
            myQueue.push(y);
        }       
    }
    
    int pop() {
        int y = myQueue.front(); 
        myQueue.pop();
        return y; 
    }
    
    int top() {
        return myQueue.front();
    }
    
    bool empty() {
        if (myQueue.empty()) {
            return true; 
        }
        else {
            return false; 
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */