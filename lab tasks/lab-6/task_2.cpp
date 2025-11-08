#include <iostream>
#include <vector>
using namespace std;

class Stack
{
    vector<int> s;
public:
    void push(int val)
    {
        s.push_back(val);
    }

    void pop()
    {
        if(!s.empty())
        {
            s.pop_back();
        }
        else
        {
            cout << "Stack is empty\n";
        }
    }

    int top()
    {
        if(!s.empty())
        {
            return s.back();
        }
        else
        {
            cout << "Stack is empty\n";
            return 0;
        }
    }

    bool empty()
    {
        return s.empty();
    }
};

int evaluatePostfix(string expr)
{
    Stack st;

    for(int i=0;i<expr.length();i++)
    {
        char ch = expr[i];

        if(isdigit(ch))
        {
            st.push(ch - '0');
        }
        else
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            int res;

            switch(ch)
            {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                default: 
                    cout << "Invalid operator: " << ch << "\n";
                    return 0;
            }

            st.push(res);
        }
    }

    return st.top();
}

int main()
{
    string expr;
    cout << "Enter postfix expression: ";
    cin >> expr;

    int result = evaluatePostfix(expr);
    cout << "Result: " << result << endl;

    return 0;
}
