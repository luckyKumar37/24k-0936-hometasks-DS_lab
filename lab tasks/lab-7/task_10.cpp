#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int getMax(vector<int>& arr) {
    int mx = arr[0];
    for(int i = 1; i < arr.size(); i++)
        if(arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for(int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for(int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int>& arr) {
    int m = getMax(arr);
    for(int exp = 1; m / exp > 0; exp *= 10) {
        cout << "\nSorting by digit place " << setw(5) << exp << "s:\n";
        countingSort(arr, exp);
        for(int x : arr)
            cout << x << " ";
        cout << endl;
    }
}

int main() {
    vector<int> ids = {
        50213, 41235, 62341, 18976, 98712, 32015, 55678, 23456, 87654, 11111,
        99999, 65432, 34567, 12345, 88888, 77777, 66666, 44444, 33333, 22222
    };

    cout << "Before Sorting:\n";
    for(int x : ids)
        cout << x << " ";
    cout << endl;

    radixSort(ids);

    cout << "\nAfter Sorting:\n";
    for(int x : ids)
        cout << x << " ";
    cout << endl;

    return 0;
}
