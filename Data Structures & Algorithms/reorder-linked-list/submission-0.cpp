/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr)
            return;

        deque<ListNode*> deq;
        
        ListNode* temp = head->next;
        while(temp!=nullptr)
        {
            deq.push_back(temp);
            temp=temp->next;
        }
        ListNode* finalLL = head;
        while(deq.empty()==false)
        {
            finalLL->next = deq.back();
            finalLL = finalLL->next;
            deq.pop_back();
            if(deq.empty())
            {
                finalLL->next = nullptr;
                return;
            }
            finalLL->next = deq.front();
            finalLL=finalLL->next;
            deq.pop_front();
            if(deq.empty())
            {
                finalLL->next=nullptr;
                return;
            }
        }
        return;


    }
};
