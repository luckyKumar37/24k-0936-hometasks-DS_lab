#include <iostream>
using namespace std;

struct Student
{
    string name;
    int score;
    Student* next;
};

class StudentList
{
    Student* head;
public:
    StudentList()
    {
        head = nullptr;
    }

    void add(string name, int score)
    {
        Student* newNode = new Student;
        newNode->name = name;
        newNode->score = score;
        newNode->next = head;
        head = newNode;
    }

    void display()
    {
        Student* temp = head;
        cout << "Name\tScore\n";
        while(temp != nullptr)
        {
            cout << temp->name << "\t" << temp->score << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    int getMax()
    {
        int maxVal = 0;
        Student* temp = head;
        while(temp != nullptr)
        {
            if(temp->score > maxVal)
                maxVal = temp->score;
            temp = temp->next;
        }
        return maxVal;
    }

    void radixSort()
    {
        int maxScore = getMax();
        int exp = 1;

        while(maxScore/exp > 0)
        {
            Student* buckets[10] = {nullptr};
            Student* tails[10] = {nullptr};

            Student* curr = head;
            while(curr != nullptr)
            {
                int digit = (curr->score / exp) % 10;
                Student* nextNode = curr->next;
                curr->next = nullptr;

                if(buckets[digit] == nullptr)
                {
                    buckets[digit] = curr;
                    tails[digit] = curr;
                }
                else
                {
                    tails[digit]->next = curr;
                    tails[digit] = curr;
                }

                curr = nextNode;
            }
            

            Student* newHead = nullptr;
            Student* newTail = nullptr;
            for(int i=0;i<10;i++)
            {
                if(buckets[i] != nullptr)
                {
                    if(newHead == nullptr)
                    {
                        newHead = buckets[i];
                        newTail = tails[i];
                    }
                    else
                    {
                        newTail->next = buckets[i];
                        newTail = tails[i];
                    }
                }
            }

            head = newHead;
            exp *= 10;
        }
    }
};

int main()
{
    StudentList students;


    students.add("Alice", 88);
    students.add("Bob", 95);
    students.add("Charlie", 72);
    students.add("David", 85);
    students.add("Eve", 90);

    cout << "Before sorting:\n";
    students.display();

    students.radixSort();

    cout << "After sorting:\n";
    students.display();

    return 0;
}
