#include <iostream>
#include <vector>
using namespace std;

struct Runner
{
    string name;
    int time; 
};

void merge(vector<Runner>& arr, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<Runner> L(n1), R(n2);

    for(int i=0;i<n1;i++)
    {
        L[i] = arr[l + i];
    }
    for(int i=0;i<n2;i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    int i=0, j=0, k=l;
    while(i<n1 && j<n2)
    {
        if(L[i].time <= R[j].time)
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while(i<n1)
    {
        arr[k++] = L[i++];
    }
    while(j<n2)
    {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<Runner>& arr, int l, int r)
{
    if(l >= r)
        return;

    int mid = l + (r-l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, r, mid);
}

int main()
{
    vector<Runner> runners(10);


    for(int i=0;i<10;i++)
    {
        cout << "Enter name of runner " << i+1 << ": ";
        cin >> runners[i].name;
        cout << "Enter finish time (seconds): ";
        cin >> runners[i].time;
    }

    mergeSort(runners, 0, runners.size()-1);

    cout << "\nTop 5 fastest runners:\n";
    for(int i=0;i<5;i++)
    {
        cout << i+1 << ". " << runners[i].name << " - " << runners[i].time << " sec\n";
    }

    return 0;
}
