#include <iostream>
#include <vector>
using namespace std;

struct Order
{
    int orderID;
    string customerName;
    double totalPrice;
};

int partition(vector<Order>& arr, int l, int r)
{
    double pivot = arr[r].totalPrice;
    int i = l - 1;

    for(int j = l; j < r; j++)
    {
        if(arr[j].totalPrice < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(vector<Order>& arr, int l, int r)
{
    if(l < r)
    {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

int main()
{
    vector<Order> orders = {
        {101, "Alice", 450.75},
        {102, "Bob", 120.50},
        {103, "Charlie", 980.00},
        {104, "David", 300.20},
        {105, "Eve", 150.00}
    };

    cout << "Original Orders:\n";
    for(int i = 0; i < orders.size(); i++)
    {
        cout << "OrderID: " << orders[i].orderID 
             << ", Customer: " << orders[i].customerName 
             << ", Total: $" << orders[i].totalPrice << endl;
    }

    quickSort(orders, 0, orders.size() - 1);

    cout << "\nSorted Orders by Total Price (Ascending):\n";
    for(int i = 0; i < orders.size(); i++)
    {
        cout << "OrderID: " << orders[i].orderID 
             << ", Customer: " << orders[i].customerName 
             << ", Total: $" << orders[i].totalPrice << endl;
    }

    return 0;
}
