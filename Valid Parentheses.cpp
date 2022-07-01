class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        string x = "({[";
        for (auto it : s)
        {
            if (x.find(it) != string::npos)
                st.push(it);
            else
            {
                if (st.empty())
                    return 0;
                char ch = st.top();
                if (it == ')')
                {
                    if (ch != '(')
                        return 0;
                    st.pop();
                }
                else if (it == '}')
                {
                    if (ch != '{')
                        return 0;
                    st.pop();
                }
                else
                {
                    if (ch != '[')
                        return 0;
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};