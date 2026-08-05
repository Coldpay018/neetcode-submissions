class LRUCache {
public:
    unordered_map <int,int>mp;
    struct ListNode{
        int data;
        ListNode* next;

        ListNode(int a)
        {
            data = a;
            next = nullptr;
        }

        ListNode(int a, ListNode* b)
        {
            data = a;
            next = b;
        }
    };
    int max_capacity = 0;
    ListNode* dummy = new ListNode(-1);
    ListNode* curr = dummy;
    ListNode* prev = dummy;
    ListNode* temp;
    ListNode* temp2;
    LRUCache(int capacity) {
        int count = 0;
        while(count!=capacity)
        {
            ListNode* newNode = new ListNode(-1);
            curr->next = newNode;
            curr = curr->next;
            count++;
        }
        max_capacity = capacity;

    }
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        if(key==dummy->next->data)
            return mp[key];
        prev = dummy;
        curr = dummy->next;
        while(curr->data!=key)
        {
            prev = prev->next;
            curr = curr->next;
        }
        temp = curr->next;
        temp2 = dummy->next;
        dummy->next = curr;
        curr->next = temp2;
        prev->next = temp;
        return mp[key];
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end())
        {
            mp[key] = value;
            temp = dummy->next;
            dummy->next = new ListNode(key);
            dummy->next->next = temp;
            temp = dummy;
            if(mp.size()>max_capacity)
            {
                temp = dummy->next;
                prev = dummy;
                while(temp->next!=nullptr && temp->next->data!=-1)
                {
                    prev = prev->next;
                    temp = temp->next;
                }
                mp.erase(temp->data);
                prev->next = nullptr;
            }
        }
        if(dummy->next->data == key)
        {
            mp[key]=value;
            return;
        }
        mp[key] = value;
        prev = dummy;
        curr = dummy->next;
        while(curr->data !=key)
        {
            prev = prev->next;
            curr=curr->next;
        }
        temp = curr->next;
        temp2 = dummy->next;
        dummy->next = curr;
        curr->next = temp2;
        prev->next = temp;
    }
};
