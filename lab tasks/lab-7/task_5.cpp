#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int cmp_first = 0, cmp_random = 0, cmp_middle = 0, cmp_median = 0;

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

int partition(vector<int>& arr, int l, int r, int& cmp)
{
    int pivot = arr[r];
    int i = l - 1;
    for(int j = l; j < r; j++)
    {
        cmp++;
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

// First element pivot
void quicksort_first(vector<int>& arr, int l, int r)
{
    if(l < r)
    {
        swap(arr[l], arr[r]);
        int p = partition(arr, l, r, cmp_first);
        quicksort_first(arr, l, p - 1);
        quicksort_first(arr, p + 1, r);
    }
}

// Random pivot
void quicksort_random(vector<int>& arr, int l, int r)
{
    if(l < r)
    {
        int pivotIndex = l + rand() % (r - l + 1);
        swap(arr[pivotIndex], arr[r]);
        int p = partition(arr, l, r, cmp_random);
        quicksort_random(arr, l, p - 1);
        quicksort_random(arr, p + 1, r);
    }
}

// Middle element pivot
void quicksort_middle(vector<int>& arr, int l, int r)
{
    if(l < r)
    {
        int mid = (l + r) / 2;
        swap(arr[mid], arr[r]);
        int p = partition(arr, l, r, cmp_middle);
        quicksort_middle(arr, l, p - 1);
        quicksort_middle(arr, p + 1, r);
    }
}

// Median of three pivot
int median_of_three(vector<int>& arr, int l, int r)
{
    int mid = (l + r) / 2;
    if(arr[l] > arr[mid]) swap(arr[l], arr[mid]);
    if(arr[l] > arr[r]) swap(arr[l], arr[r]);
    if(arr[mid] > arr[r]) swap(arr[mid], arr[r]);
    swap(arr[mid], arr[r]);
    return arr[r];
}

void quicksort_median(vector<int>& arr, int l, int r)
{
    if(l < r)
    {
        median_of_three(arr, l, r);
        int p = partition(arr, l, r, cmp_median);
        quicksort_median(arr, l, p - 1);
        quicksort_median(arr, p + 1, r);
    }
}

void print(vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    srand(time(0));
    vector<int> base = {9, 3, 7, 1, 5, 8, 2, 6, 4};
    
    vector<int> a1 = base;
    vector<int> a2 = base;
    vector<int> a3 = base;
    vector<int> a4 = base;

    quicksort_first(a1, 0, a1.size() - 1);
    quicksort_random(a2, 0, a2.size() - 1);
    quicksort_middle(a3, 0, a3.size() - 1);
    quicksort_median(a4, 0, a4.size() - 1);

    cout << "Sorted Array:\n";
    print(a1);

    cout << "\nComparisons:\n";
    cout << "First Element Pivot: " << cmp_first << endl;
    cout << "Random Element Pivot: " << cmp_random << endl;
    cout << "Middle Element Pivot: " << cmp_middle << endl;
    cout << "Median of Three Pivot: " << cmp_median << endl;

    return 0;
}
