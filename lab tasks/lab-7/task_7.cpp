#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<int>& arr)
{
    int mx = arr[0];
    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

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
    int m = getMax(arr);
    for(int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

int main()
{
    vector<int> scores = {
        88, 45, 92, 67, 53, 100, 34, 76, 58, 84,
        91, 72, 60, 50, 95, 66, 79, 41, 90, 73,
        99, 35, 80, 48, 64, 70, 77, 52, 83, 55,
        85, 94, 97, 61, 46, 40, 68, 93, 74, 42,
        81, 87, 78, 89, 82, 69, 56, 71, 63, 59
    };

    cout << "Original Scores:\n";
    for(int i = 0; i < scores.size(); i++)
        cout << scores[i] << " ";
    cout << "\n\n";

    radixSort(scores);

    cout << "Sorted Scores (Ascending):\n";
    for(int i = 0; i < scores.size(); i++)
        cout << scores[i] << " ";
    cout << "\n\n";

    cout << "Student Ranks:\n";
    for(int i = 0; i < scores.size(); i++)
        cout << "Rank " << scores.size()-i << " -> Score: " << scores[i] << endl;

    return 0;
}
