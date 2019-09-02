/*
  Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
  Populate each next pointer to point to its next right node. If there is no next right node,
  the next pointer should be set to NULL.

  Initially, all next pointers are set to NULL.

  Note:
  You may only use constant extra space.
  Example :

  Given the following binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7
  After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
  Note 1: that using recursion has memory overhead and does not qualify for constant space.
  Note 2: The tree need not be a perfect binary tree.
  
*/
// O(n) space solution with queue
void Solution::connect(TreeLinkNode* A) {
    if(A==NULL)
    return;
    queue<TreeLinkNode*> q;
    q.push(A);
    q.push(NULL);
    while(q.size()!=1)
    {
        int size = q.size()-1;
        int i=0;
        while(i<size)
        {
            TreeLinkNode* temp = q.front();
            q.pop();
            temp->next = q.front();
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
            i++;
        }
        q.pop();
        q.push(NULL);
    }
}

/* o(1) space
  TreeLinkNode *getRight(TreeLinkNode *root)
  {
      TreeLinkNode *temp=root->next;

      while(temp!=NULL)
      {
          if(temp->left)
              return temp->left;
          if(temp->right)
              return temp->right;
          temp=temp->next;
      }

      return NULL;
  }

  void Solution::connect(TreeLinkNode* A) {
      TreeLinkNode *temp=NULL,*parent=A;

      if(A==NULL)
          return;

      A->next=NULL;    

      if(A->left==NULL && A->right==NULL)
          return;  

      while(parent!=NULL)
      {
          temp=parent;

          while(temp!=NULL)
          {
              if(temp->left)
              {
                  if(temp->right)
                      temp->left->next=temp->right;
                  else 
                      temp->left->next=getRight(temp);
              }

              if(temp->right)
                  temp->right->next=getRight(temp);

              temp=temp->next;    
          }

          if(parent->left)
              parent=parent->left;
          else if(parent->right);
              parent=parent->right;
          else
              parent=getRight(parent);
      }
  }
  
*/
