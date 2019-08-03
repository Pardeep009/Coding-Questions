/*  A binary tree node has data, pointer to left child
    and a pointer to right child  
    struct Node {
        int data;
        Node* right;
        Node* left;

        Node(int x) {
            data = x;
            right = NULL;
            left = NULL;
        }
    }; 
*/
bool check(Node *root,int min,int max)
{
    if(root == NULL)
    return true;
    if(root->data>=min && root->data<=max && check(root->left,min,root->data) && check(root->right,root->data,max))  // check root element should lie in a range of max and min,now,check same for left subtree and right subtree
    return true;      // bst
    else
    return false;      // not bst
}

bool isBST(Node* root) {
    // Your code here
    return check(root,INT_MIN,INT_MAX);

}
