#include<iostream>
#include<string>
using namespace std;

class Researchpaper
{
    string* authors;
    int size;
    
public:
    Researchpaper(int n)
    {
        authors = new string[n];
        size = n;

        for(int i=0;i<size;i++)
        {
            authors[i] = "";
        }
    }

    void addAuthor(string s,int idx)
    {
        if(idx < size)
        {
            authors[idx] = s;
        }
    }

    Researchpaper(Researchpaper& rp)
    {
        size = rp.size;
        authors = new string[size];

        for (int i=0;i<size;i++)
        {
            authors[i] = rp.authors[i];
        }
    }

    Researchpaper& operator=(const Researchpaper& rp)
    {
        if(this != &rp)
        {
            delete[] authors;
            size = rp.size;
            authors = new string[size];

            for (int i=0;i<size;i++)
            {
                authors[i] = rp.authors[i];
            }
        }
        return *this;
    }

    ~Researchpaper()
    {
        delete[] authors;
    }

    void display()
    {
        for(int i=0;i<size;i++)
        {
            cout << authors[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Researchpaper rp1(4);
    rp1.addAuthor("Alice", 0);
    rp1.addAuthor("Bob", 1);
    rp1.addAuthor("Charlie", 2);

    rp1.display();

    Researchpaper rp2 = rp1;
    rp2.addAuthor("David", 3);

    rp2.display();

    Researchpaper rp3(4);
    rp3 = rp1;
    rp3.addAuthor("Eve", 3);
    rp3.display();
    return 0;
}