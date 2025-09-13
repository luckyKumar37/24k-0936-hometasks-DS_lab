#include<iostream>
using namespace std;
class BankAccount{
private:
    double balance;
public:
    BankAccount() : balance(0.0){}
    BankAccount(double initialBalance) : balance(initialBalance){}
    BankAccount(const BankAccount &other) : balance(other.balance){}
    void withdraw(double amount){
        if(amount<=balance){

            balance-=amount;
        }
        else{
            cout<<"Insufficient balance!"<<endl;
        }
    }
    double getBalance() const{
        return balance;
    }
};
int main(){
    BankAccount account1;
    cout<<account1.getBalance()<<endl;
    BankAccount account2(1000);
    cout<<account2.getBalance()<<endl;
    BankAccount account3=account2;
    account3.withdraw(200);
    cout<<account3.getBalance()<<endl;
    cout<<account2.getBalance()<<endl;
    return 0;
}