#include <iostream>
using namespace std;

class Exam
{
    int *marks;
public:
    Exam()
    {
        marks = new int[5];
        for(int i = 0; i < 5; i++)
        {
            marks[i] = 0;
        }
    }

    Exam(int val)
    {
        marks = new int[5];
        for(int i = 0; i < 5; i++)
        {
            marks[i] = val;
        }
    }

    void setMarks(int val, int idx)
    {
        if (idx >= 0 && idx < 5)
        {
            marks[idx] = val;
        }
    }   

    void display()
    {
        cout << "Marks: ";
        for(int i = 0; i < 5; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
    }

    ~Exam()
    {
        delete[] marks;
    }
};

int main() 
{
    Exam e1(90);
    Exam e2 = e1;

    e1.display();
    e2.display();

    e2.setMarks(92,2);
    e1.display();
    e2.display();

    return 0;
}
