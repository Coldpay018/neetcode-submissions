class Solution {
public:
    struct compare{
        int x;

        compare(int val)
        {
            x = val;
        }

        bool operator()(int a, int b)
        {
            if(abs(a-x)==abs(b-x))
                return a < b;
            else
                return abs(a-x) < abs(b-x);
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(),arr.end(), compare(x));
        vector<int> temp;
        for(int i=0; i<k; i++)
        {
            temp.push_back(arr[i]);
        }
        sort(temp.begin(), temp.end());
        return temp;
    }
};