/*
  You are given two non-empty linked lists representing two non-negative integers. 
  The most significant digit comes first and each of their nodes contain a single digit.
  Add the two numbers and return it as a linked list.
  (reversing the lists is not allowed.)
  
  Example:
  Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output: 7 -> 8 -> 0 -> 7
  
*/
class Solution {
public:
    
    ListNode *add(int len1,int len2,ListNode* l1, ListNode* l2)
    {
        int sum,carry;
        ListNode *prev = NULL;
        if(l1 == NULL && l2 == NULL)
        {
            return new ListNode(0);
        }
        else if(len1>len2)
        {
            prev = add(len1-1,len2,l1->next,l2);
            sum = prev->val + l1->val;
        }
        else if(len1<len2)
        {
            prev = add(len1,len2-1,l1,l2->next);
            sum = prev->val + l2->val;
        }
        else
        {
            prev = add(len1,len2,l1->next,l2->next);
            sum = prev->val + l1->val + l2->val;
        }
        prev->val = sum%10;
        carry = sum/10;
        ListNode *temp = new ListNode(carry);
        temp->next = prev;
        return temp;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0,len2 = 0;
        ListNode *temp1 = l1,*temp2 = l2;
        while(temp1)
        {
            len1++;
            temp1 = temp1->next;
        }
        while(temp2)
        {
            len2++;
            temp2 = temp2->next;
        }
        temp1 = add(len1,len2,l1,l2);
        if(temp1->val == 0)
        {
            temp1 = temp1->next;
        }
        return temp1;
    }
    
};
