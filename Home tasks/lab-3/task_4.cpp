#include <iostream>
using namespace std;

class Node
{
public:
    int ticketId;
    string CostumerName;
    string RideName;
    Node* next;

    Node(int id, string cname, string rname) : ticketId(id), CostumerName(cname), RideName(rname), next(NULL) {}
};

class circularLinkedList
{
private:
    Node* head;

public:
    circularLinkedList() : head(NULL) {}

    void issueTicketAtEnd(int id, string cname, string rname)
    {
        Node* t = new Node(id, cname, rname);
        if (!head)
        {
            head = t;
            t->next = head; 
            return;
        }

        Node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = t;
        t->next = head;
    }

    void issuePriorityTIcketAtFront(int id, string cname, string rname)
    {
        Node* t = new Node(id, cname, rname);
        if (!head)
        {
            head = t;
            t->next = head; 
            return;
        }

        Node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = t;
        t->next = head;
        head = t;
    }

    void cancelTicket(int id)
    {
        if (!head)
        {
            cout << "No tickets to cancel!" << endl;
            return;
        }

        if (head->ticketId == id)
        {
            if (head->next == head)
            {
                delete head;
                head = NULL;
                return;
            }

            Node* temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }

            Node* toDelete = head;
            head = head->next;
            temp->next = head;
            delete toDelete;
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        do
        {
            prev = curr;
            curr = curr->next;
            if (curr->ticketId == id)
            {
                prev->next = curr->next;
                delete curr;
                return;
            }
        } while (curr != head);

        cout << "Ticket ID " << id << " not found!" << endl;
    }

    void cancelFirstTicket()
    {
        if (!head)
        {
            cout << "No tickets to cancel!" << endl;
            return;
        }

        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        Node* toDelete = head;
        head = head->next;
        temp->next = head;
        delete toDelete;
    }

    void searchTicket(int id)
    {
        if (!head)
        {
            cout << "No tickets available!" << endl;
            return;
        }

        Node* temp = head;
        do
        {
            if (temp->ticketId == id)
            {
                cout << "Ticket ID: " << temp->ticketId << ", Costumer Name: " << temp->CostumerName << ", Ride Name: " << temp->RideName << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Ticket ID " << id << " not found!" << endl;
    }

    void displayTickets()
    {
        if (!head)
        {
            cout << "No tickets available!" << endl;
            return;
        }

        Node* temp = head;
        do
        {
            cout << "Ticket ID: " << temp->ticketId << ", Costumer Name: " << temp->CostumerName << ", Ride Name: " << temp->RideName << endl;
            temp = temp->next;
        } while (temp != head);
    }

    void totalTickets()
    {
        if (!head)
        {
            cout << "Total tickets: 0" << endl;
            return;
        }

        int count = 0;
        Node* temp = head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);

        cout << "Total tickets: " << count << endl;
    }

    void NextTicket(int id)
    {
        if (!head)
        {
            cout << "No tickets available!" << endl;
            return;
        }

        Node* temp = head;
        do
        {
            if (temp->ticketId == id)
            {
                if (temp->next != head)
                {
                    cout << "Next Ticket ID: " << temp->next->ticketId << ", Costumer Name: " << temp->next->CostumerName << ", Ride Name: " << temp->next->RideName << endl;
                }
                else
                {
                    cout << "This is the last ticket. Next ticket is the first ticket." << endl;
                    cout << "Next Ticket ID: " << head->ticketId << ", Costumer Name: " << head->CostumerName << ", Ride Name: " << head->RideName << endl;
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Ticket ID " << id << " not found!" << endl;
    }

    ~circularLinkedList()
    {
        if (!head) return;

        Node* curr = head;
        Node* nextNode;

        do
        {
            nextNode = curr->next;
            delete curr;
            curr = nextNode;
        } while (curr != head);

        head = NULL;
    }


};

int main() 
{
    circularLinkedList cll;
    cll.issueTicketAtEnd(101, "Alice", "Roller Coaster");
    cll.issueTicketAtEnd(102, "Bob", "Ferris Wheel");
    cll.issuePriorityTIcketAtFront(100, "Charlie", "Haunted House");
    cll.displayTickets();
    cll.totalTickets();
    cll.searchTicket(102);
    cll.NextTicket(102);
    cll.cancelTicket(101);
    cll.displayTickets();
    cll.cancelFirstTicket();
    cll.displayTickets();
    cll.totalTickets();

    return 0;
}