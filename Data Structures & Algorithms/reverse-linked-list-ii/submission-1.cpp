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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* theNodeBeforeReverse = new ListNode();
        int count=1;
        while(count!=left)
        {
            if(count+1==left)
                theNodeBeforeReverse = prev;
            prev = prev->next;
            curr = curr->next;
            count++;
        }
        ListNode* temp = new ListNode();
        ListNode* firstNode = prev;
    
        while(count!=right)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            count++;
        }
        firstNode->next = curr;
        if(left!=1)
        {
            theNodeBeforeReverse->next = prev;
            return head;
        }
        if(left==1)
            return prev;
        return head;
    }
};