#include <iostream>
#include <vector>
using namespace std;

struct Call 
{
    string name;
    string number;
    int duration;
};

class Stack 
{
    vector<Call> s;
public:
    void push(Call c) 
    {
        s.push_back(c);
    }

    void pop() 
    {
        if(!s.empty())
            s.pop_back();
        else
            cout << "No call history to delete\n";
    }

    Call top() 
    {
        if(!s.empty())
            return s.back();
        else 
        {
            cout << "No recent call\n";
            return {"", "", 0};
        }
    }

    bool empty() 
    {
        return s.empty();
    }

    void display() 
    {
        if(s.empty()) 
        {
            cout << "No call history\n";
            return;
        }
        cout << "\nCurrent Call Log:\n";
        for(int i=s.size()-1;i>=0;i--) 
        {
            cout << s[i].name << " | " << s[i].number << " | " << s[i].duration << " min\n";
        }
        cout << endl;
    }
};

int main() 
{
    Stack callLog;
    int ch;
    do 
    {
        cout << "1. Add Call\n2. Delete Recent Call\n3. View Recent Call\n4. Check if Empty\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        if(ch==1) 
        {
            Call c;
            cout << "Enter name: ";
            cin >> c.name;
            cout << "Enter number: ";
            cin >> c.number;
            cout << "Enter duration (min): ";
            cin >> c.duration;
            callLog.push(c);
            callLog.display();
        }
        else if(ch==2) 
        {
            callLog.pop();
            callLog.display();
        }
        else if(ch==3) 
        {
            Call last = callLog.top();
            if(last.name != "")
                cout << "Last Call -> " << last.name << " | " << last.number << " | " << last.duration << " min\n";
        }
        else if(ch==4) 
        {
            if(callLog.empty())
                cout << "Call history is empty\n";
            else
                cout << "Call history is not empty\n";
        }

    } while(ch != 5);

    return 0;
}
