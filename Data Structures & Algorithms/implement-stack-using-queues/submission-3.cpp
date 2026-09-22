class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int a;
        int b = q1.back();

        while(!q1.empty())
        {
            a = q1.front();
            q1.pop();
            q2.push(a);
        }
        while(q2.size()>1)
        {
            a = q2.front();
            q2.pop();
            q1.push(a); 
        }
        q2.pop();
        return b;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        if(q1.empty())
            return true;
        return false;
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