class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int i=0; 
        int ans = 0;
        while(i<tokens.size())
        {
            if(isdigit(tokens[i][0]) || (tokens[i][0]=='-' && tokens[i].size()>1))
                st.push(stoi(tokens[i]));
            else
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                if(tokens[i]=="+")
                    a = b + a;

                else if(tokens[i]=="-")
                    a = b - a;
                    
                else if(tokens[i]=="*")
                    a = b * a;
                    
                else if(tokens[i]=="/")
                    a = b/a;
                st.push(a);
            }
            i++;
        }
        return st.top();
    }
};
