class MinStack {
public:

    stack <long long int >st ; 
    long long int minval ; 
    MinStack() {
        
    }
    
    void push(int value) {
        if (st.empty()){
            st.push(value) ; 
            minval  = value ; 
        }
        else if(minval > value ){
            st.push((long long)2*value - minval) ; 
            minval = value ; 
        }
        else{
            st.push(value) ; 
        }
    }
    
    void pop() {
        if (minval > st.top()){
            minval  = 2*minval - st.top() ; 
        }
        st.pop() ; 
    }
    
    int top() {
        if(st.top()< minval){
            return minval ; 
        }
        return st.top() ; 
    }
    
    int getMin() {
        return minval ; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna