#include <iostream>
using namespace std;

class Box
{
    int *volume;

public:
    Box()
    {
        volume = new int;
        *volume = 0;
    }

    Box(int val)
    {
        volume = new int;
        *volume = val;
    }
    Box(const Box& b)
    {
        volume = new int;
        *volume = *(b.volume);
    }

    Box& operator=(const Box& b)
    {
        if(this != &b)
        {
            delete volume;
            volume = new int;
            *volume = *(b.volume);
        }
        return *this;
    }

    void setVolume(int val)
    {
        *volume = val;
    }

    void display()
    {
        cout << "Volume: " << *volume << endl;
    }

    ~Box()
    {
        delete volume;
    }
};

int main() 
{
    Box b1(100);
    Box b2 = b1; 
    Box b3;
    b3 = b1; 
    b1.display();
    b2.display();
    b3.display();

    b2.setVolume(200);
    b1.display();
    b2.display();
    b3.display();

    return 0;
}