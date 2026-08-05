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
    long long reverse(long long a)
    {
        long long new_num = 0;
        while(a>=10)
        {
            new_num = new_num*10 + (a%10);
            a=floor(a/10);
        }
        new_num = new_num*10 + a;
        return new_num;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* ptr1 = l1;
        // ListNode* ptr2 = l2;

        // long long a = 0;
        // long long b = 0;

        // while(ptr1!=nullptr)
        // {
        //     a = a*10 + ptr1->val;
        //     ptr1 = ptr1->next;
        // }
        // while(ptr2!=nullptr)
        // {
        //     b = b*10 + ptr2->val;
        //     ptr2 = ptr2->next;
        // }

        // a = reverse(a);
        // b = reverse(b);

        // long long c = a + b;

        // ListNode* finalLLHead = new ListNode(c%10);
        // c = floor(c/10);
        // ListNode* curr = finalLLHead;
        // while(c!=0)
        // {
        //     ListNode* newNode = new ListNode(c%10);
        //     curr->next = newNode;
        //     curr = newNode;
        //     c=floor(c/10);
        // }

        // curr->next=nullptr;
        // return finalLLHead;

        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        int carry = 0;
        int sum = 0;
        sum = l1->val + l2->val;
        ListNode* newLLhead = new ListNode(sum%10);
        ListNode* curr = newLLhead;
        carry = sum/10;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        while((ptr1!=nullptr || ptr2!=nullptr) || carry != 0)
        {
            if(ptr1==nullptr && ptr2==nullptr)
            {
                ListNode* newNode = new ListNode(carry);
                curr->next = newNode;
                curr->next->next = nullptr;
                return newLLhead;
            }

            if(ptr1==nullptr)
            {
                sum = carry + ptr2->val;
                ListNode* newNode = new ListNode(sum%10);
                curr->next = newNode;
                curr=curr->next;
                carry = sum/10;
                ptr2 = ptr2->next;
                continue;
            }

            if(ptr2==nullptr)
            {
                sum  = carry+ptr1->val;
                ListNode* newNode = new ListNode(sum%10);
                curr->next = newNode;
                curr=curr->next;
                carry = sum/10;
                ptr1 = ptr1->next;
                continue;
            }
            sum = ptr1->val+ptr2->val+carry;
            ListNode* newNode = new ListNode(sum%10);
            curr->next = newNode;
            curr = curr->next;
            carry = sum/10;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        curr->next=nullptr;
        return newLLhead;
    }
};
