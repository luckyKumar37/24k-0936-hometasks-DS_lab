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
            s.pop_back();
    }

    int top()
    {
        if(!s.empty())
            return s.back();
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

int evaluatePrefix(string expr)
{
    Stack st;

    // Scan expression from right to left
    for(int i=expr.length()-1;i>=0;i--)
    {
        char ch = expr[i];

        if(isdigit(ch))
        {
            st.push(ch - '0');
        }
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int res;

            switch(ch)
            {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                case '^': 
                {
                    res = 1;
                    for(int j=0;j<b;j++)
                        res *= a;
                    break;
                }
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
    cout << "Enter prefix expression: ";
    cin >> expr;

    int result = evaluatePrefix(expr);
    cout << "Result: " << result << endl;

    return 0;
}
