/*

  Given a linked list consisting of L nodes and given a number N.
  The task is to find the Nth node from the end of the linked list.
  
  Example:
  Input:
  2
  9 2
  1 2 3 4 5 6 7 8 9
  4 5
  10 5 100 5

  Output:
  8
  -1

  Explanation:
  Testcase 1: In the first example, there are 9 nodes in linked list and we need to find 2nd node from end.  
  2nd node from end os 8.  
  Testcase 2: In the second example, there are 4 nodes in linked list and we need to find 5th from end. 
  Since 'n' is more than number of nodes in linked list, output is -1.
  
*/
void printNthFromLast(struct Node *head, int n) 
{ 
    struct Node *main_ptr = head; 
    struct Node *temp = head; 

    int count = 0; 
    if(head != NULL) 
    {
      while( count < n ) 
      { 
        if(temp == NULL) 
        { 
          printf("-1");            // n is greater than the no. of nodes in list 
          return; 
        } 
        temp = temp->next; 
        count++; 
      }

      while(temp != NULL) 
      { 
        main_ptr = main_ptr->next; 
        temp = temp->next; 
      } 
      printf("%d",main_ptr->data); 
    }
    else
    {
      printf("List is Empty");
    }
    
} 
