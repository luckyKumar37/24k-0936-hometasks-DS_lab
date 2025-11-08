#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op)
{
    if(op == '^')
        return 3;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else
        return 0;
}

bool isRightAssociative(char op)
{
    return op == '^';
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infixToPostfix(string expr)
{
    stack<char> st;
    string result = "";

    for(int i=0;i<expr.length();i++)
    {
        char c = expr[i];

        if(isalnum(c))
        {
            result += c;
        }
        else if(c == '(')
        {
            st.push(c);
        }
        else if(c == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop(); // discard '('
        }
        else if(isOperator(c))
        {
            while(!st.empty() && isOperator(st.top()))
            {
                char topOp = st.top();
                if((!isRightAssociative(c) && precedence(c) <= precedence(topOp)) ||
                   (isRightAssociative(c) && precedence(c) < precedence(topOp)))
                {
                    result += topOp;
                    st.pop();
                }
                else
                {
                    break;
                }
            }
            st.push(c);
        }
    }

    while(!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

int main()
{
    string expr;
    cout << "Enter infix expression: ";
    cin >> expr;

    string postfix = infixToPostfix(expr);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
