#include <iostream>
using namespace std;

class Node
{
public:
    int itemId;
    string itemName;
    int itemPrice;
    Node* next;
    Node* prev;

    Node(int id,string name,int p):itemId(id),itemName(name),itemPrice(p),next(NULL),prev(NULL){}

};

class doublyLinkedList
{
private:
    Node* head;

public:
    doublyLinkedList():head(NULL){}
    void insertAtEnd(int id,string n,int p)
    {
        Node* t = new Node(id,n,p);
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
        t->prev = temp;
        temp->next = t;
    }

    void insertAtFront(int id,string n,int p)
    {
        Node* t = new Node(id,n,p);
        if(!head)
        {
            head = t;
            return;
        }

        t->next = head;
        head->prev = t;
        head = t;
    }

    void removeFirst()
    {
        if(!head) return;
        Node* temp = head;
        head = head->next;
        if(head)
            head->prev = NULL;

        delete temp;
    }

    void removeLast()
    {
        if(!head) return;

        if(!head->next)
        {
            removeFirst();
            return;
        }

        Node* temp = head;
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        delete temp;

    }

    void Search(int id)
    {
        if(!head)
        {
            cout<<"item id:"<<id<<" does not exist in the linked list!"<<endl;
            return;
        }

        Node* temp = head;

        while(temp)
        {
            if(temp->itemId == id)
            {
                cout<<"Item id:"<<temp->itemId<<endl;
                cout<<"Item Name:"<<temp->itemName<<endl;
                cout<<"Item Price:"<<temp->itemPrice<<endl;
                return;
            }
            temp = temp->next;
        }

        cout<<"item id:"<<id<<" does not exist in the linked list!"<<endl;

    }

    void update(int id,int np)
    {
        if(!head)
        {
            cout<<"item id:"<<id<<" does not exist in the linked list!"<<endl;
            return;
        }

        Node* temp = head;

        while(temp)
        {
            if(temp->itemId == id)
            {
                temp->itemPrice = np;
                return;
            }
            temp = temp->next;
        }

        cout<<"item id:"<<id<<" does not exist in the linked list!"<<endl;
    
    }

    void displayFrontTOEnd()
    {
        Node* temp = head;
        while(temp)
        {
            cout<<"Item id:"<<temp->itemId<<endl;
            cout<<"Item Name:"<<temp->itemName<<endl;
            cout<<"Item Price:"<<temp->itemPrice<<endl;  
            temp = temp->next;         
        }
        
    }

    void displayEndToFront()
    {
        Node* temp = head;
        while(temp->next)
        {
            temp = temp->next;
        }

        while(temp)
        {
            cout<<"Item id:"<<temp->itemId<<endl;
            cout<<"Item Name:"<<temp->itemName<<endl;
            cout<<"Item Price:"<<temp->itemPrice<<endl;  
            temp = temp->prev;             
        }

    }

    void length()
    {
        Node* temp = head;
        int c = 0;
        while(temp)
        {
            c++;
            temp = temp->next;
        }  
        
        cout<<"length of Cart is:"<<c<<endl;
    }

    void maxPrice()
    {
        Node* temp = head;
        int maxp = 0;
        while(temp)
        {
            maxp = max(maxp,temp->itemPrice);
            temp = temp->next;
        }

        Node* t = head;
        while(t)
        {
            if(t->itemPrice == maxp)
            {
                cout<<"Item id:"<<t->itemId<<endl;
                cout<<"Item Name:"<<t->itemName<<endl;
                cout<<"ItemPrice:"<<t->itemPrice<<endl;
                return;
            }
            t = t->next;
        }

    }

    ~doublyLinkedList()
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
    doublyLinkedList cart;

    cart.insertAtEnd(101, "Apple", 50);
    cart.insertAtEnd(102, "Banana", 30);
    cart.insertAtFront(103, "Orange", 40);

    cout << "Display from front to end:" << endl;
    cart.displayFrontTOEnd();

    cout << "\nDisplay from end to front:" << endl;
    cart.displayEndToFront();

    cout << "\nSearching for item with id 102:" << endl;
    cart.Search(102);

    cout << "\nUpdating price of item with id 101 to 60:" << endl;
    cart.update(101, 60);

    cout << "\nDisplay after update:" << endl;
    cart.displayFrontTOEnd();

    cout << "\nRemoving first item:" << endl;
    cart.removeFirst();
    cart.displayFrontTOEnd();

    cout << "\nRemoving last item:" << endl;
    cart.removeLast();
    cart.displayFrontTOEnd();

    cout << "\nLength of cart:" << endl;
    cart.length();

    cout << "\nItem with maximum price:" << endl;
    cart.maxPrice();

    return 0;
}