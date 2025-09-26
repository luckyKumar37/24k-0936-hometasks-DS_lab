#include <iostream>
#include<vector>
using namespace std;

int interpolationSearch(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key) return low;
            return -1;
        }
        int pos = low + ((high - low) / (arr[high] - arr[low])) * (key - arr[low]);
        if (arr[pos] == key)
            return pos;
        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int shellSort(vector<int>&arr, int n) 
{
    for(int gap = n/2; gap > 0; gap /= 2) 
    {
        for(int i = gap; i < n; i++) 
        {
            int temp = arr[i];
            int j;
            for(j = i; j >= gap; j -= gap) 
            {
                if(arr[j - gap] > temp)
                {
                    arr[j] = arr[j - gap];
                }
                else
                {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
}

void printArray(vector<int>&arr, int n) 
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}  

int main() 
{
    vector<int> arr = {34, 7, 23, 32, 5, 62};

    int n = arr.size();
    cout << "Unsorted array: ";
    printArray(arr, n);

    shellSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    int key = 23;
    int index = interpolationSearch(arr, key);
    if (index != -1)
        cout << "Element " << key << " found at index " << index << endl;
    else
        cout << "Element " << key << " not found." << endl;

    return 0;
}