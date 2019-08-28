/*
  Given a binary search tree, write a function to find the kth smallest element in the tree.
  Example :

  Input : 
    2
   / \
  1   3

  and k = 2

  Return : 2

  As 2 is the second smallest element in the tree.

*/
int findSmallest(TreeNode* A,int B,int &c)
 {
    if(A==NULL)
    return 0;
    
    int lt = findSmallest(A->left,B,c);
    if(lt)
    return lt;
    
    c++;
    
    if(c==B)
    return A->val;
    
    return findSmallest(A->right,B,c);
 }
int Solution::kthsmallest(TreeNode* A, int B) {
    int c=0;
    return findSmallest(A,B,c);
}
