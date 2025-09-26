#include <iostream>
#include<vector>
using namespace std;

void shellSort(vector<int>&arr, int n) 
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

    return 0;
}