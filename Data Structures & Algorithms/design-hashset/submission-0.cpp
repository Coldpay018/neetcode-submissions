class MyHashSet {
public:
    vector<int> arr;
    MyHashSet() {
        
    }
    
    void add(int key) {
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]==key)
                return;
        }
        arr.push_back(key);
    }
    
    void remove(int key) {
        int c=0;
        for(int c=0; c<arr.size(); c++)
        {
            if(arr[c]==key)
            {
                arr.erase(arr.begin()+c);
                break;
            }
        }
    }
    
    bool contains(int key) {
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]==key)
                return true;
        }
        return false;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */