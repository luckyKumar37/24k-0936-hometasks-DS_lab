#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Patron
{
    string name;
    int numBooks;
};

void printPatron(Patron p)
{
    cout << "Patron Name: " << p.name << ", Books: " << p.numBooks << endl;
}

int main()
{
    queue<Patron> libraryQueue;
    int choice;

    do
    {
        cout << "1. Add Patron to Queue\n2. Complete Patron Transaction\n3. View Current Queue\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if(choice == 1)
        {
            Patron p;
            cout << "Enter patron name: ";
            getline(cin, p.name);
            cout << "Enter number of books: ";
            cin >> p.numBooks;
            cin.ignore();

            libraryQueue.push(p);
            cout << "Patron added to the queue.\n\n";
        }
        else if(choice == 2)
        {
            if(!libraryQueue.empty())
            {
                Patron p = libraryQueue.front();
                cout << "Completing transaction for:\n";
                printPatron(p);
                libraryQueue.pop();
                cout << "Transaction completed.\n\n";
            }
            else
            {
                cout << "No patrons in the queue.\n\n";
            }
        }
        else if(choice == 3)
        {
            if(libraryQueue.empty())
            {
                cout << "No patrons waiting.\n\n";
            }
            else
            {
                cout << "Current patrons in queue:\n";
                queue<Patron> temp = libraryQueue; 
                while(!temp.empty())
                {
                    printPatron(temp.front());
                    temp.pop();
                }
                cout << endl;
            }
        }
        else if(choice != 4)
        {
            cout << "Invalid choice. Please try again.\n\n";
        }

    } while(choice != 4);

    return 0;
}
