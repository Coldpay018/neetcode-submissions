/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* bfs_traversal(Node* node)
    {
        if(node==nullptr)
            return node;
        unordered_map<int,Node*> visited;
        queue<Node*> q;
        q.push(node);
        Node* root;
        int flag = 0;
        while(!q.empty())
        {
            Node* a;
            if(!visited.contains(q.front()->val))
            {
                a  = new Node(q.front()->val);
                if(flag==0)
                    root = a;
                flag = 1;
            } else{
                a = visited[q.front()->val];
            }

            for(Node* i : q.front()->neighbors)
            {
                if(!visited.contains(i->val))
                {
                    Node* b = new Node(i->val);
                    a->neighbors.push_back(b);
                    visited[b->val]=b;
                    q.push(i);
                } else
                {
                    a->neighbors.push_back(visited[i->val]);
                }
            }
            q.pop();
        }
        return root;
    }
    Node* cloneGraph(Node* node) {
        return bfs_traversal(node);
        
    }
};
//If visited array size == n  then we will return
//Add the node in the visited array once a new replica node has been created and its neighbors have been explored
//
