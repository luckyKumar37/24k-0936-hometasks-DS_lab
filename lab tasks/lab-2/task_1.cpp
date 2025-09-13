#include<iostream>
using namespace std;

class Vector
{
private:
    int *arr;
    int size;
    int capacity;

public:
    Vector(int n)
    {
        arr = new int[n];
        capacity = n;
        size = 0;
    }

    void Resize()
    {
        int newcapa = capacity*2;
        int *t = new int[newcapa];
        for(int i=0;i<size;i++)
        {
            t[i] = arr[i];
        }

        delete arr;
        arr = t;
        capacity = newcapa;
    }

    void push(int a)
    {
        if(size == capacity)
        {
            Resize();
        }
        arr[size++] = a;
        

    }

    void display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

    void getSize()
    {
        cout<<"Size:"<<size<<endl;
    }

    void getCapacity()
    {
        cout<<"Capacity:"<<capacity<<endl;
    }

    ~Vector()
    {
        delete[] arr;
    }


};

int main()
{
    Vector v(4);
    v.push(1);
    v.push(1);
    v.push(1);
    v.push(1);
    v.push(2);

    v.display();
    v.getCapacity();
    v.getSize();
}
