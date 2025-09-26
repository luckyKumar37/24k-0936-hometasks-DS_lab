#include <iostream>
using namespace std;

void bubbleSort(int arr[],int n)
{
    bool swapped;
    for(int i=0;i<n-1;i++)
    {
        swapped = false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped) break;
    }

}

int main() 
{
    int arr[] = {64,34,25,12,22,11,90};

    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    bubbleSort(arr,7);

    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;
}