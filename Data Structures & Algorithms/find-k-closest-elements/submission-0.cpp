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
            {
                return a<b;
            }
            else
            {
                return abs(a-x) < abs(b-x);
            }
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> elements;
        for(int i=0; i<k; i++)
        {
            elements.push_back(arr[i]);
        }
        int ele = x;
        int i = k;
        sort(elements.begin(),elements.end(), compare(ele));
        while(i<arr.size())
        {
            int last = elements.back();
            if(abs(arr[i]-ele) < abs(last-ele))
            {
                elements.pop_back();
                elements.push_back(arr[i]);
                sort(elements.begin(),elements.end(), compare(ele));
            }
            else if(abs(arr[i]-ele) == abs(last-ele) && arr[i] < last)
            {
                elements.pop_back();
                elements.push_back(arr[i]);
                sort(elements.begin(),elements.end(), compare(ele));
            }
            i++;

        }
        sort(elements.begin(),elements.end());
        return elements;

        
    }
};