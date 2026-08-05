/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)
            return nullptr;
        Node* deepcopy = new Node(head->val);
        Node* temp = head->next;
        Node* curr = deepcopy;
        while(temp!=nullptr)
        {
            Node* newNode = new Node(temp->val);
            curr->next = newNode;
            if(temp->next==nullptr)
            {
                curr->next->next=nullptr;
                break;
            }
            curr = newNode;
            temp = temp->next;
        }
        curr = deepcopy;
        temp = head;
        unordered_map<Node*,Node*> mp;
        while(temp!=nullptr)
        {
            mp[temp] = curr;
            temp=temp->next;
            curr = curr->next; 
        }
        temp = head;
        while(temp!=nullptr)
        {
            mp[temp]->random = mp[temp->random];
            temp=temp->next;
        }
        return deepcopy;

    }
};
