class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j = numbers.size()-1;
        while(i<numbers.size())
        {
            while(numbers[j]>=target-numbers[i])
            {    
                if(numbers[i]+numbers[j]==target)
                    return {i+1, j+1};
                else
                    j--;
            }
            i++;
        } 
        return {0,0};
        
    }
};
