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
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* ans = new ListNode();
        ListNode* a  = ans;
        while(temp1!=nullptr && temp2!=nullptr)
        {
            if(temp1->val < temp2->val)
            {
                ans->next = temp1;
                temp1 = temp1->next;
            }
            else
            {
                ans->next = temp2;
                temp2 = temp2->next;
            }
            ans = ans->next;
        }
        while(temp1!=nullptr)
        {
            ans->next = temp1;
            temp1 = temp1->next;
            ans = ans->next;
        }
        while(temp2!=nullptr)
        {
            ans->next = temp2;
            temp2 = temp2->next;
            ans = ans->next;
        }
        ans = nullptr;
        return a->next;
    }
};
