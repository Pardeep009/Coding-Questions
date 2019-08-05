/*
  Problem Link:-> https://www.interviewbit.com/problems/partition-list/
  Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
  You should preserve the original relative order of the nodes in each of the two partitions.

  For example,
  Given 1->4->3->2->5->2 and x = 3,
  return 1->2->2->4->3->5.
  
*/

ListNode* Solution::partition(ListNode* A, int B) {
    if(A == NULL || A->next == NULL)
    return A;
    ListNode *temp = A,*first = NULL,*prev = NULL;         // first maitains last node(from begining) whose value is less than x
    int f=0;          // flag,if 1 means a higher value node has occurred
    while(temp)
    {
        if(f && temp->val<B)
        {
            prev->next = temp->next;
            if(first==NULL)           // if first==NULL means head value is greater than x
            {
                temp->next = A;
                A = temp;
            }
            else                        
            {
                temp->next = first->next;
                first->next = temp;
            }
            first = temp;
            temp = prev; 
        }
        else if(temp->val<B)
        {
            first = temp;
            f=0;
        }
        else
        {
            f=1;
        }
        prev = temp;
        temp = temp->next;
    }
    return A;
}
