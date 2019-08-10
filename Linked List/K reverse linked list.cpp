/*
   Given a singly linked list and an integer K, reverses the nodes of the
   list K at a time and returns modified linked list.

   NOTE : The length of the list is divisible by K 
   
   Example :
   Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,
   O/P list is 2 -> 1 -> 4 -> 3 -> 6 -> 5
  
   Constant extra space solution required.
   
*/
ListNode *reverse(ListNode *head,int B)
 {
    ListNode *prev = NULL,*curr = head,*next = curr->next;
    for(int i=1;i<=B;i++)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        if(curr)
        next = curr->next;
    }
    head->next = curr;
    return prev;
 }
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(A==NULL|| A->next==NULL || B==1)
    return A;
    ListNode *curr = A;
    ListNode *start = A;
    ListNode *prev = NULL;
    while(curr)
    {
        prev = reverse(curr,B);
        if(curr == A)
        {
            A = prev;
        }
        else
        {
            start->next = prev;
        }
        start = curr;
        curr = curr->next;
    }
    return A;
}
