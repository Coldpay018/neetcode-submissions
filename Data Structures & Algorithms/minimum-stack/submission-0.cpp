class MinStack {
public:
    stack <int> st1;
    stack <int> st2;
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
    }
    
    void pop() {
        st1.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        int min_ele = INT_MAX;
        while(!st1.empty())
        {
            min_ele = min(st1.top(), min_ele);
            int a = st1.top();
            st1.pop();
            st2.push(a);
        }

        while(!st2.empty())
        {
            int a = st2.top();
            st2.pop();
            st1.push(a);
        }
        return min_ele;
        
    }
};
