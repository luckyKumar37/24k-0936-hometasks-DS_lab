#include <iostream>
using namespace std;

int sumDigits(int n)
{
    if(n == 0) return 0;

    return n%10 + sumDigits(n/10);
}

int nestedSum(int n)
{
    if(n < 10) return n;

    int sum_of_curr = sumDigits(n);

    return nestedSum(sum_of_curr);

}

int main() 
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"sum of digits: "<<sumDigits(n)<<endl;
    cout<<"final single digit result is: "<<nestedSum(n)<<endl;



    return 0;
}