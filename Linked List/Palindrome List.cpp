/*

  Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

  Expected solution is linear in time and constant in space.
  For example,

  List 1-->2-->1 is a palindrome.
  List 1-->2-->3 is not a palindrome.
  
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 int ispal(ListNode* slow,ListNode* fast,ListNode* &c)
 {
    if(fast == NULL)
    {
        c = slow;
        return 1;
    }
    else if(fast->next == NULL)
    {
        c = slow->next;
        return 1;
    }
    else
    {
        if(ispal(slow->next,fast->next->next,c))
        {
           if(slow->val == c->val)
           {
               c = c->next;
               return 1;
           }
           else
           return 0;
        }
        else
        {
            return 0;
        }
    }
 }
int Solution::lPalin(ListNode* A) {
    if(A->next == NULL )
    return 1;
    ListNode *c=NULL;
    return ispal(A,A,c);
}
