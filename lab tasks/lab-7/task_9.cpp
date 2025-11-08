#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr, int exp)
{
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for(int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for(int i = n - 1; i >= 0; i--)
    {
        int idx = (arr[i] / exp) % 10;
        output[count[idx] - 1] = arr[i];
        count[idx]--;
    }

    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int>& arr)
{
    int mx = arr[0];
    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] > mx)
            mx = arr[i];
    }

    for(int exp = 1; mx / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

int main()
{
    vector<int> transactions = {
        1200, 450, 3200, 800, 1200, 560, 950, 3050, 1200, 700
    };

    cout << "Original Transaction Amounts:\n";
    for(int i = 0; i < transactions.size(); i++)
        cout << transactions[i] << " ";
    cout << "\n\n";

    radixSort(transactions);

    cout << "Sorted Transaction Amounts (Ascending):\n";
    for(int i = 0; i < transactions.size(); i++)
        cout << transactions[i] << " ";
    cout << endl;

    return 0;
}
