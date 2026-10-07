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
    Node* explore_bfs(Node* node)
    {
        vector<Node*> visited;
        queue<Node*> q;
        int j;
        Node* new_node = new Node(node->val);
        visited.push_back(new_node);
        if(node->neighbors.size()==0)
            return new_node;
        for(Node* i : node->neighbors)
        {
            Node* n = new Node(i->val);
            visited.push_back(n);
            q.push(i);
            new_node->neighbors.push_back(n);
        }

        while(!q.empty())
        {
            int flag = 0;
            for(int j=0; j<visited.size(); j++)
            {
                if(visited[j]->val == q.front()->val && visited[j]->neighbors.size()==q.front()->neighbors.size())
                {
                    q.pop();
                    flag = 1;
                    break;
                }
            }
            if(flag==1)
                continue;
            Node* b = q.front();
            q.pop();
            for(Node* i: b->neighbors)
            {
                j=0;
                while(j<visited.size() && visited[j]->val != i->val)
                    j++;
                if (j<visited.size())
                {
                    int k=0;
                    while(k<visited.size() && visited[k]->val != b->val)
                        k++;
                    visited[k]->neighbors.push_back(visited[j]);
                    continue;
                }
                Node* new_n = new Node(i->val);
                visited.push_back(new_n);
                q.push(i);
                j=0;
                while(j<visited.size() && visited[j]->val != b->val)
                    j++;

                visited[j]->neighbors.push_back(new_n);
            }
        }
        return new_node;
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
            return nullptr;
        return explore_bfs(node);

    }
};
