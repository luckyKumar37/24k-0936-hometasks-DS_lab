#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cout<<"how many courses you want to register:";
    cin>>n;
    cin.ignore();
    string **courses;
    for(int i=0;i<n;i++)
    {
        string temp;
        cout<<"write the name of course:";
        getline(cin,temp);
        cin.ignore();
        courses[i] = new string(temp);
    }
    for(int i=0;i<n;i++)
    {
        cout<<courses[i]<<endl;
    }
    
    for(int i=0;i<n;i++)
    {
        delete courses[i];
    }
    delete courses;
    return 0;

}