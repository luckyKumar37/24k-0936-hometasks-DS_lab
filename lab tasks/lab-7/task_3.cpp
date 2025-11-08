#include <iostream>
#include <vector>
#include<string>
using namespace std;

struct Product
{
    string name;
    double price;
    string description;
    bool availability;
};

int partition(vector<Product>& arr, int l, int r)
{
    double pivot = arr[r].price;
    int i = l - 1;

    for(int j=l;j<r;j++)
    {
        if(arr[j].price < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[r]);
    return i+1;
}

void quickSort(vector<Product>& arr, int l, int r)
{
    if(l < r)
    {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}

void displayProducts(const vector<Product>& arr)
{
    cout << "Sorted Product List by Price:\n";
    for(int i=0;i<arr.size();i++)
    {
        cout << i+1 << ". " << arr[i].name << " - $" << arr[i].price
             << " | " << arr[i].description
             << " | " << (arr[i].availability ? "Available" : "Not Available") << endl;
    }
    cout << endl;
}

int main()
{
    vector<Product> products(3);

    for(int i=0;i<3;i++)
    {
        cout << "Enter details for product " << i+1 << ":\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, products[i].name);
        cout << "Price: ";
        cin >> products[i].price;
        cin.ignore();
        cout << "Description: ";
        getline(cin, products[i].description);
        cout << "Availability (1 for available, 0 for not): ";
        cin >> products[i].availability;
        cin.ignore();
        cout << endl;
    }

    quickSort(products, 0, products.size()-1);
    displayProducts(products);

    return 0;
}
