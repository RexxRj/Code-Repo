class Solution {

    vector<string> getExp(string& expression)
    {
        stack<char> st;
        st.push(expression[1]);
        vector<string> temp;
        int i = 2;
        string res = "";
        while(!st.empty())
        {
            if(expression[i] == '(')
            {
                st.push(expression[i]);
                res+= expression[i];
            }
            else if(expression[i] == ')')
            {
                st.pop();

                if(!st.empty())
                res+= expression[i];
            }
            else if(expression[i] == ',' && st.size() == 1)
            {
                temp.push_back(res);
                res = "";
            }else
            {
                res+= expression[i];
            } 
            i++;
        }

        temp.push_back(res);

        return temp;
    }

public:
    bool parseBoolExpr(string expression) {
        
        if(expression[0] == 't')
        return true;

        if(expression[0] == 'f')
        return false;

        if(expression[0] == '!')
        {
            string res = "";
            for(int i = 2; i<expression.size()-1; i++)
            res+= expression[i];

            return !parseBoolExpr(res);
        }

        if(expression[0] == '&')
        {
            
            vector<string> temp = getExp(expression);
            bool ans = true;

            for(auto& exp: temp)
            ans = ans && parseBoolExpr(exp);

            return ans;


        }

        if(expression[0] == '|')
        {
            vector<string> temp = getExp(expression);

            bool ans = false;

            for(auto& exp: temp)
            ans = ans || parseBoolExpr(exp);

            return ans;
        }

        return false;
    }
};