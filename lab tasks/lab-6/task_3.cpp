#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    string url;
    Node* next;
};

class LinkedList
{
    Node* head;
public:
    LinkedList()
    {
        head = nullptr;
    }

    void addFront(string url)
    {
        Node* newNode = new Node;
        newNode->url = url;
        newNode->next = head;
        head = newNode;
    }

    void removeFront()
    {
        if(head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    string getFront()
    {
        if(head != nullptr)
            return head->url;
        return "";
    }

    void display()
    {
        Node* temp = head;
        cout << "Current browsing history: ";
        while(temp != nullptr)
        {
            cout << temp->url << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Stack
{
    vector<string> s;
public:
    void push(string url)
    {
        s.push_back(url);
    }

    void pop()
    {
        if(!s.empty())
            s.pop_back();
    }

    string top()
    {
        if(!s.empty())
            return s.back();
        return "";
    }

    bool empty()
    {
        return s.empty();
    }
};

void backButton(LinkedList& history, Stack& st, int times)
{
    for(int i=0;i<times;i++)
    {
        if(!st.empty())
        {
            st.pop();
            history.removeFront();
        }
    }
}

int main()
{
    LinkedList history;
    Stack st;

    vector<string> websites = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};

    for(int i=0;i<websites.size();i++)
    {
        history.addFront(websites[i]);
        st.push(websites[i]);
    }

    cout << "Before clicking back button:\n";
    history.display();

    backButton(history, st, 2);

    cout << "After clicking back button twice:\n";
    history.display();

    cout << "Current page: " << history.getFront() << endl;

    return 0;
}
