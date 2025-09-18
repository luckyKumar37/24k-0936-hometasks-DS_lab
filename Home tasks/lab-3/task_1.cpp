#include <iostream>
using namespace std;

class Node
{
public:
    string val;
    int price;
    Node* next;

    Node(string val,int p):val(val),price(p),next(NULL){};
};

class linkedList
{
private:
    Node* head;

public:
    linkedList():head(NULL){}
    void addAtFront(string val,int p)
    {
        Node* t = new Node(val,p);
        if(!head)
        {
            head = t;
            return;
        }

        t->next = head;
        head = t;
    }

    void addAtEnd(string val,int p)
    {
        Node* t = new Node(val,p);
        if(!head)
        {
            head = t;
            return;
        }

        Node* temp = head;
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = t;        
    }

    void insertAfter(string prev,string val,int p)
    {
        if(!head) return;

        Node* t = new Node(val,p);
        Node* temp = head;

        while(temp && temp->val != prev)
        {
            temp = temp->next;
        }

        if(!temp)
        {
            cout<<"value "<<prev<<" does not exist in the linked list!"<<endl;
            return;
        }

        t->next = temp->next;
        temp->next = t;

    }

    void Search(string val)
    {
        if(!head)
        {
            cout<<"value "<<val<<" does not exist in the linked list!"<<endl;
            return;
        }

        Node* temp = head;

        while(temp)
        {
            if(temp->val == val)
            {
                cout<<"price of "<<val<<" is $"<<temp->price<<endl;
                return;
            }
            temp = temp->next;
        }


        cout<<"value "<<val<<" does not exist in the linked list!"<<endl;

    }

    void display()
    {
        Node* temp = head;

        while(temp)
        {
            cout<<temp->val<<" - $"<<temp->price<<endl;
            temp = temp->next;
        }

    }

    ~linkedList()
    {
        Node* temp = head;
        while(temp)
        {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }

};

int main() 
{
    linkedList l1;
    l1.addAtFront(string("Smartwatch"),200);
    l1.addAtEnd(string("Phone"),500);
    l1.addAtEnd(string("Keyboard"),80);
    l1.insertAfter(string("Phone"),string("Monitor"),300);
    l1.Search(string("Tablet"));
    l1.display();
    

    return 0;
}