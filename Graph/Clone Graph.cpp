/*
  Problem Link :-> https://www.interviewbit.com/problems/clone-graph/
  Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
*/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
void cloneutil(UndirectedGraphNode *node,unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> &um)
{
    if(um.find(node)==um.end())
    {
        UndirectedGraphNode* head = new UndirectedGraphNode(node->label);
        um[node] = head;
        for(int i=0;i<node->neighbors.size();i++)
        {
            cloneutil(node->neighbors[i],um);
        }   
    }
}
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if(node == NULL)
    return NULL;
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> um;
    UndirectedGraphNode* head = new UndirectedGraphNode(node->label);
    um[node] = head;
    queue<UndirectedGraphNode*> q;
    q.push(node);
    while(q.size())
    {
        UndirectedGraphNode* temp = q.front();
        q.pop();
        UndirectedGraphNode* clonetemp = um[temp];
        for(int i=0;i<temp->neighbors.size();i++)
        {
            UndirectedGraphNode* ne = temp->neighbors[i];
            if(um.find(ne)==um.end())
            {
                UndirectedGraphNode* newnode = new UndirectedGraphNode(ne->label);
                clonetemp->neighbors.push_back(newnode);
                um[ne] = newnode;
                q.push(ne);
            }
            else {
                clonetemp->neighbors.push_back(um[ne]);
            }
        }
    }
    return head;
}
