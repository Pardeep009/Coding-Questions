/*
  Given a Binary Tree with N edges. The task is to extract all leaves of it in a Doubly Linked List (DLL).
  Note that the DLL need to be created in-place. Assume that the node structure of DLL and Binary Tree is same,
  only the meaning of left and right pointers are different. In DLL, left means previous pointer and right means next pointer. 
  Head of DLL should point to the left most leaf and then in inorder traversal and so on.
*/
Node *givehead(Node *root,Node **head_ref,Node **tail_ref)
{
    if(root == NULL)
    {
        return *head_ref;
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(*head_ref == NULL)
            {
                *head_ref = root;
                *tail_ref = root;
            }
            else
            {
                Node *temp = *tail_ref;
                temp->right = root
                root->left = *tail_ref;
                *tail_ref = root;
            }
        }
        else
        {
            givehead(root->left,head_ref,tail_ref);
            givehead(root->right,head_ref,tail_ref);
        }
        return *head_ref;
    }
}
Node *convertToDLL(Node *root,Node **head_ref)        // called from main
{
    //add code here.
    Node *tail_ref = NULL;
    return givehead(root,head_ref,&tail_ref);
}
