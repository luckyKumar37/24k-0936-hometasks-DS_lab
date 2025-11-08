#include <iostream>
#include <vector>
using namespace std;

struct Employee
{
    string name;
    int id;
    double salary;
};

void merge(vector<Employee>& arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<Employee> left(n1);
    vector<Employee> right(n2);

    for(int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2)
    {
        if(left[i].salary >= right[j].salary)
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Employee>& arr, int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void displayTop3(vector<Employee>& arr)
{
    cout << "\nTop 3 Highest Paid Employees:\n";
    cout << "--------------------------------\n";
    for(int i = 0; i < 3 && i < arr.size(); i++)
    {
        cout << "Name: " << arr[i].name
             << ", ID: " << arr[i].id
             << ", Salary: $" << arr[i].salary << endl;
    }
}

int main()
{
    vector<Employee> employees = {
        {"Alice", 101, 72000},
        {"Bob", 102, 55000},
        {"Charlie", 103, 88000},
        {"David", 104, 94000},
        {"Eve", 105, 61000},
        {"Frank", 106, 75000},
        {"Grace", 107, 82000},
        {"Hank", 108, 97000},
        {"Ivy", 109, 50000},
        {"Jack", 110, 66000},
        {"Kathy", 111, 87000},
        {"Leo", 112, 93000}
    };

    mergeSort(employees, 0, employees.size() - 1);

    cout << "Employees sorted by salary (descending):\n";
    cout << "----------------------------------------\n";
    for(int i = 0; i < employees.size(); i++)
    {
        cout << employees[i].name << " (ID: " << employees[i].id 
             << ") - $" << employees[i].salary << endl;
    }

    displayTop3(employees);

    return 0;
}
