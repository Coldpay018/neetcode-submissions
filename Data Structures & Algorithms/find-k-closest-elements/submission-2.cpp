class Solution {
public:
    int closer_element(int l, int r, int x)
    {
        if(abs(l-x) == abs(r-x))
            return l;
        else if(abs(l-x) < abs(r-x))
            return l;
        else
            return r;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = k;
        vector<int> ans;
        while(r<arr.size())
        {
            if(closer_element(arr[l], arr[r], x)==arr[r])
            {
                l++;
                r++;
            }
            else
            {
                break;
            }
        }
        for(int i=l; i<r; i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};