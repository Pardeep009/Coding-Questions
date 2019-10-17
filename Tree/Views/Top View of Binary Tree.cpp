//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

void generateview(Node *root,map<int,pair<int,int>> &m,int height,int index)
{
    if(root == NULL)
    return;
    generateview(root->left,m,height+1,index-1);
    generateview(root->right,m,height+1,index+1);
    if(m.find(index) == m.end())
    {
        m[index] = make_pair(root->data,height);   
    }
    else
    {
        pair<int,int> p = m[index];
        if(p.second>height)
        {
            m[index].second = height;
            m[index].first = root->data;
        }
    }
}
// function should print the topView of the binary tree
void topView(struct Node *root)
{
    //Your code here
    map<int,pair<int,int>> m;
    generateview(root,m,0,0);
    map < int, pair < int, int > > ::iterator it; 
    for (it = m.begin(); it != m.end(); ++it) 
    { 
        pair < int, int > p = it -> second; 
        cout << p.first << " "; 
    } 
}
