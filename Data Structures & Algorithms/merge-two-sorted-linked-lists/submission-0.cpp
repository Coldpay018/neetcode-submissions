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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* h1 = list1;
        ListNode* h2 = list2;

        if(h1==nullptr)
            return h2;
        else if(h2==nullptr || (h1==nullptr && h2==nullptr))
            return h1;

        if(h1->val <= h2->val)
        {
            while(h1->next!=nullptr  && h2!=nullptr)
            {
                while(h1->next != nullptr && h1->next->val <= h2->val)
                {
                    h1=h1->next;
                }
                ListNode* temp1 = h1->next;
                ListNode* temp2 = h2->next;
                h1->next = h2;
                h2->next = temp1;

                h1 = h2;
                h2 = temp2;  
            }
            if(h2!=nullptr)
            {
                h1->next = h2;
            }
            return list1;
        }
        else
        {
            while(h2->next!=nullptr && h1!=nullptr)
            {
                while(h2->next != nullptr && h2->next->val <= h1->val)
                {
                    h2 = h2->next;
                }
                ListNode* temp1 = h2->next;
                ListNode* temp2 = h1->next;
                h2->next = h1;
                h1->next = temp1;

                h2 = h1;
                h1 = temp2; 
            }
            if(h1!=nullptr)
            {
                h2->next = h1;
            }
            return list2;
        }
        return list1;
    }
};
