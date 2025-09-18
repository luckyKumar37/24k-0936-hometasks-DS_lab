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
    void addAtTail(string val,int p)
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

    void deleteFromFront()
    {
        if(!head){
            cout<<"linked list is empty!"<<endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
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
    }

    void Search(int pos)
    {
        Node* temp = head;
        int c=0;
        while(c != pos-1)
        {
            c++;
            temp = temp->next;
        }

        cout<<temp->val<<" - $"<<temp->price<<endl;

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
    linkedList list;
    list.addAtTail("Apple", 120);
    list.addAtTail("Banana", 60);
    list.addAtTail("Orange", 80);

    cout << "Displaying all items:" << endl;
    list.display();

    cout << "\nSearching for 'Banana':" << endl;
    list.Search("Banana");

    cout << "\nSearching for item at position 2:" << endl;
    list.Search(2);

    cout << "\nDeleting from front..." << endl;
    list.deleteFromFront();

    cout << "\nDisplaying all items after deletion:" << endl;
    list.display();

    return 0;
}