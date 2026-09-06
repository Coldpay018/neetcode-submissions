class Solution {
public:

    struct Compare {
        bool operator()(const vector<int>& a, const vector<int>& b)
        {
            return a[0]*a[0] + a[1]*a[1] > b[0]*b[0] + b[1]*b[1];
        }
    };
    priority_queue< vector<int>, vector<vector<int>>, Compare> pq;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(vector<int> i : points)
        {
            pq.push(i);
        }

        vector<vector<int>> ans;
        int count = 0;

        while(count!=k)
        {
            vector<int> temp = pq.top();
            ans.push_back(temp);
            pq.pop();
            count++;
        }

        return ans;

    }
};
