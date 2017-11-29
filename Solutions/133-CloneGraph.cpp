/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:

    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;


    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

        if(node == NULL) return NULL;


        if(mp.find(node) == mp.end()){
            mp[node] = new UndirectedGraphNode(node->label);
            int len = node->neighbors.size();

            for(int i = 0; i < len; i++){
                mp[node]->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }
        }

        return mp[node];
    }
};
