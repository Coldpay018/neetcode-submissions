class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
        
    }
    
    int pop() {
        s2={};
        while(s1.size()>=2)
        {
            int a = s1.top();
            s2.push(a);
            s1.pop();
        }
        int t = s1.top();
        s1.pop();
        while(!s2.empty())
        {
            int c = s2.top();
            s1.push(c);
            s2.pop();
        }
        s2={};
        return t;
        
    }
    
    int peek() {
        s2={};
        int b;
        while(!s1.empty())
        {
            b = s1.top();
            s1.pop();
            s2.push(b);
        }
        while(!s2.empty())
        {
            int d = s2.top();
            s1.push(d);
            s2.pop();
        }

        return b;
        
    }
    
    bool empty() {
        if(s1.empty())
            return true;
        return false;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */