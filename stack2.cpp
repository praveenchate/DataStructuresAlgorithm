#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int priority(char c)
{
    if (c == '^')
        return 3;

    else if (c == '*' || c == '/')
        return 2;

    else if (c == '+' || c == '-')
        return 1;

    return -1;
}

string reverse(string &s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {

        swap(s[i], s[n - i - 1]);
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
            // i++;
        }
    }

    return s;
}
// Function to convert an infix expression to a postfix expression.
string infixToPostfix(string &s)
{
    // Your code here
    int i = 0;
    std::stack<char> st;
    string ans = "";
    int n = s.length();

    while (i < n)
    {
        char ch = s[i];
        // 1.Check for the operands A-Z a-z 0-9
        if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')
        {
            ans += ch;
        }
        // 2.Check for open brackets
        else if (ch == '(')
        {
            st.push(ch);
        }
        // 3.check for the closing brackets
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        // 4.check for the operators
        else
        {
            while (!st.empty() && priority(ch) <= priority(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
        i++;
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

string infixToPrefix(string &s)
{
    stack<int> st;
    s = reverse(s);
    int n = s.length();
    string ans = "";

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        // 1.for opernads
        if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')
        {
            ans += ch;
        }

        // 2.for brackets
        //    open bracket
        else if (ch == '(')
        {
            st.push(ch);
        }

        // close braket
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != ')')
            {
                ans += st.top();
                st.pop();
            }
        }

        // 3.operators
        else
        {
            if (s[i] == '^')
            {
                while (priority(s[i]) <= priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            else
            {
                while (priority(s[i]) < priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
    }
    ans = reverse(s);
    return ans;
}

int main()
{
    // string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string infix = "(A+B)*C-D+F";
    string prefix = infixToPrefix(infix);
    // cout << "Postfix: " << postfix << endl;
    cout << "Prefix: " << prefix;
    return 0;
}