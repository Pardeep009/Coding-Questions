/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
   Given a singly linked list
   L: L0 → L1 → … → Ln-1 → Ln,
  
   reorder it to:
   L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
   
   You must do this in-place without altering the nodes’ values.

   For example,
   Given {1,2,3,4}, reorder it to {1,4,2,3}.
         {1,2,3,4,5} reorder it to {1,5,2,4,3}.
 */
void changeList(ListNode *slow,ListNode *fast)
{
    static ListNode *c=NULL;
    if(fast == NULL)
    {
        c = slow;
    }
    else if(fast->next == NULL)
    {
        c = slow->next;
        slow->next = NULL;                  // for odd elements(list termination)
    }
    else
    {
        changeList(slow->next,fast->next->next);
        if(slow->next == c)
        {
            c = c->next;
            slow->next->next = NULL;        // for even elements(list termination)
        }
        else
        {
            ListNode *temp = c->next;
            c->next = slow->next;
            slow->next = c;
            c = temp;
        }
    }
}
ListNode* Solution::reorderList(ListNode* A) {
    if(A==NULL || A->next==NULL)
    return A;
    changeList(A,A);
    return A;                  // head of modified list
}
