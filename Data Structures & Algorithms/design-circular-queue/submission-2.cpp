class MyCircularQueue {
public:
    struct Node{
        int data;
        Node* next;
        
        Node(int a)
        {
            data = a;
            next = nullptr;
        }
        Node(int a, Node* b)
        {
            data = a;
            next = b;
        }
        Node()
        {
            data = -1;
            next = nullptr;
        }
    };
    Node* dummy = new Node();
    Node* curr = dummy;
    Node* currently_empty = curr;
    Node* temp = dummy;
    MyCircularQueue(int k) {
        int count = 0;
        while(count!=k)
        {
            Node* newNode = new Node();
            curr->next = newNode;
            curr = curr->next;
            count++;
        }
        curr->next = nullptr;
        currently_empty = curr;
    }
    
    bool enQueue(int value) {
        if(currently_empty==dummy)
            return false;
        while(temp->next!=currently_empty)
            temp = temp->next;
        temp->next->data = value;
        currently_empty = temp;
        temp = dummy;
        return true;
    }
    
    bool deQueue() {
        if(currently_empty->next==nullptr)
            return false;
        if(currently_empty->next->next==nullptr)
        {
            currently_empty = currently_empty->next;
            return true;
        }
        curr = dummy->next;
        int temp1 = curr->data;
        int temp2;
        while(curr->next!=nullptr)
        {
            temp2 = curr->next->data;
            curr->next->data = temp1;
            temp1 = temp2;
            curr = curr->next;
        }
        currently_empty = currently_empty->next;
        curr = dummy;
        return true;
    }
    
    int Front() {
        if(currently_empty->next==nullptr)
            return -1;
        temp = currently_empty;
        while(temp->next!=nullptr)
            temp = temp->next;
        int f = temp->data;
        temp = dummy;
        return f;
    }
    
    int Rear() {
        if(currently_empty->next==nullptr)
            return -1;
        return currently_empty->next->data;
    }
    
    bool isEmpty() {
        if(currently_empty->next==nullptr)
            return true;
        return false;
    }
    
    bool isFull() {
        if(currently_empty==dummy)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */