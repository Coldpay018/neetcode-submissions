class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(string i : operations)
        {
            if(i=="+")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.push(num1);
                st.push(num1+num2);
            }
            else if(i=="D")
                st.push(2*st.top());

            else if(i=="C")
                st.pop();
            
            else
                st.push(stoi(i));
        }
        int sum = 0;
        while(st.empty()==false)
        {
            sum+=st.top();
            st.pop();
        }

        return sum;
    }
};