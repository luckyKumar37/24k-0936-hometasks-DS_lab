#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


void guess(int tar)
{
    int n;
    cout<<"Enter your guess: ";
    cin>>n;

    if(n == tar)
    {
        cout<<"congratulations! you have guessed the number right "<<endl;
        return;
    }

    if(n>tar)
    {
        cout<<"you guess was too high\n";
    }
    else
    {
        cout<<"you guess was too low\n";
    }

    guess(tar);

}


int main() 
{
    srand(time(0));

    int target = rand()%100+1;

    guess(target);

    return 0;
}
