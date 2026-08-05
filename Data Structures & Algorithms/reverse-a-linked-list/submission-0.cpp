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
    ListNode* reverseList(ListNode* head) {
        // ListNode* start = head;
        // ListNode* end = head;
        // int cnt = 0;
        // while (end->val!=nullptr)
        // {
        //     end = end->next;
        //     cnt++;
        // }

        // if(cnt%2==0)
        // {
        //     while(start->next!=end)
        //     {
        //         int temp = start->val;
        //         start->val = end->val;
        //         temp = end->val;
        //         start=start->next
        //         end = 
        //     }
        // }

        // while (start<end)

        
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        ListNode* make_this_null = head;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        while(temp2!=nullptr)
        {
            ListNode* temp = temp2->next;
            temp2->next = temp1;
            temp1 = temp2;
            temp2 = temp;
        }
        make_this_null->next = nullptr;
        head = temp1;
        return head;
    }
};
