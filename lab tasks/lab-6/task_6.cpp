#include <iostream>
#include <queue>
#include <vector>
#include<string>
using namespace std;

struct Order
{
    int orderID;
    vector<string> items;
    vector<int> quantities;
};

void printOrder(Order o)
{
    cout << "Order ID: " << o.orderID << "\n";
    for(int i=0;i<o.items.size();i++)
    {
        cout << "  " << o.items[i] << " x" << o.quantities[i] << "\n";
    }
    cout << endl;
}

int main()
{
    queue<Order> orders;
    int choice;
    int nextID = 1;

    do
    {
        cout << "1. Add Order\n2. Process Next Order\n3. View Pending Orders\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if(choice == 1)
        {
            Order o;
            o.orderID = nextID++;
            int n;
            cout << "Enter number of items: ";
            cin >> n;
            cin.ignore();
            o.items.resize(n);
            o.quantities.resize(n);

            for(int i=0;i<n;i++)
            {
                cout << "Enter item name: ";
                getline(cin, o.items[i]);
                cout << "Enter quantity: ";
                cin >> o.quantities[i];
                cin.ignore();
            }

            orders.push(o);
            cout << "Order added successfully.\n\n";
        }
        else if(choice == 2)
        {
            if(!orders.empty())
            {
                cout << "Processing next order:\n";
                Order o = orders.front();
                printOrder(o);
                orders.pop();
            }
            else
            {
                cout << "No orders to process.\n\n";
            }
        }
        else if(choice == 3)
        {
            if(orders.empty())
            {
                cout << "No pending orders.\n\n";
            }
            else
            {
                cout << "Pending orders:\n";
                queue<Order> temp = orders; 
                while(!temp.empty())
                {
                    printOrder(temp.front());
                    temp.pop();
                }
            }
        }
        else if(choice != 4)
        {
            cout << "Invalid choice.\n\n";
        }

    } while(choice != 4);

    return 0;
}
