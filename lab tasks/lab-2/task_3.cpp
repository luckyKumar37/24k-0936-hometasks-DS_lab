#include <iostream>
using namespace std;

int main() 
{
    int **arr;
    int n;
    cout<<"Enter number of teams:";
    cin>>n;
    arr=new int*[n];
    int* score = new int[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number of players in team "<<i+1<<":";
        int m;
        cin>>m;
        arr[i]=new int[m];

        for (int j = 0; j < m; j++)
        {
            cout<<"Enter player "<<j+1<<" score:";
            cin>>arr[i][j];
        }

        score[i]=0;
        for(int j=0;j<m;j++)
        {
            score[i]+=arr[i][j];
        }
    
        
    }

    cout<<"Total scores of teams are:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Team "<<i+1<<": "<<score[i]<<endl;
    }

   for(int i=0;i<n;i++)
   {
       delete[] arr[i];
   }
   delete[] arr;
   delete[] score;
   
    return 0;
}