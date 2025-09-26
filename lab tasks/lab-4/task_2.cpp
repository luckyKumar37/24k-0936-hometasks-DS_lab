#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printArray(int arr[], int n) 
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int bubbleSort(int arr[], int n) 
{
    int comparisons = 0;
    bool swapped;
    for(int i=0; i<n-1; i++) 
    {
        swapped = false;
        for(int j=0; j<n-i-1; j++) 
        {
            comparisons++;
            if(arr[j] > arr[j+1]) 
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
    return comparisons;
}

int insertionSort(int arr[], int n) 
{
    int comparisons = 0;
    for(int i=1; i<n; i++) 
    {
        int key = arr[i];
        int j = i-1;
        while(j >= 0) 
        {
            comparisons++;
            if(arr[j] > key) 
            {
                arr[j+1] = arr[j];
                j--;
            } 
            else 
            {
                break;
            }
        }
        arr[j+1] = key;
    }
    return comparisons;
}


int selectionSort(int arr[], int n) 
{
    int comparisons = 0;
    for(int i=0; i<n-1; i++) 
    {
        int min_idx = i;
        for(int j=i+1; j<n; j++) 
        {
            comparisons++;
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        if(min_idx != i)
            swap(arr[i], arr[min_idx]);
    }
    return comparisons;
}


int shellSort(int arr[], int n) 
{
    int comparisons = 0;
    for(int gap = n/2; gap > 0; gap /= 2) 
    {
        for(int i = gap; i < n; i++) 
        {
            int temp = arr[i];
            int j;
            for(j = i; j >= gap; j -= gap) 
            {
                comparisons++;
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
    return comparisons;
}


void generateRandomArray(int arr[], int n) 
{
    for(int i=0; i<n; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
}

int main() {
    srand(time(0));
    int sizes[2] = {20, 100};
    for(int s = 0; s < 2; s++) 
    {
        int n = sizes[s];
        int arr[100], temp[100];

        cout << "\n--- Array size: " << n << " ---\n";
        generateRandomArray(arr, n);

        cout << "Original array:\n";
        printArray(arr, n);


        copy(arr, arr+n, temp);
        int cmp = bubbleSort(temp, n);
        cout << "\nBubble Sort:\nSorted array: ";
        printArray(temp, n);
        cout << "Comparisons: " << cmp << endl;

        copy(arr, arr+n, temp);
        cmp = insertionSort(temp, n);
        cout << "\nInsertion Sort:\nSorted array: ";
        printArray(temp, n);
        cout << "Comparisons: " << cmp << endl;


        copy(arr, arr+n, temp);
        cmp = selectionSort(temp, n);
        cout << "\nSelection Sort:\nSorted array: ";
        printArray(temp, n);
        cout << "Comparisons: " << cmp << endl;


        copy(arr, arr+n, temp);
        cmp = shellSort(temp, n);
        cout << "\nShell Sort:\nSorted array: ";
        printArray(temp, n);
        cout << "Comparisons: " << cmp << endl;
    }
    return 0;
}