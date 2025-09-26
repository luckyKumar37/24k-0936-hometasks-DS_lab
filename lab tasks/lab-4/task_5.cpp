#include <iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr, int n, int key) 
{
    int left = 0, right = n - 1;
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void shellSort(vector<int>& arr, int n) 
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
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    printArray(arr,n);

    shellSort(arr,n);

    printArray(arr,n);

    int key;
    cout<<"Enter the element to be searched: ";
    cin>>key;
    int result = binarySearch(arr, n, key);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}