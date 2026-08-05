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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || head->next==nullptr)
        {
            return nullptr; 
        }
        int count = 0;
        int len = 0;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            temp=temp->next;
            len++;
        }
        ListNode* prev = nullptr;

        temp = head;

        while(count!=len-n)
        {
            prev=temp;
            temp=temp->next;
            count++;
        }

        if(temp->next==nullptr)
        {
            prev->next=nullptr;
            return head;
        }
        if(temp==head)
            return head->next;
        prev->next=temp->next;
        temp->next=nullptr;
        return head;

    }
};
