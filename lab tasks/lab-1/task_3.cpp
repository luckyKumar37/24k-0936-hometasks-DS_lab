#include<iostream>
#include<string>
using namespace std;
class Playlist
{
private:
    int size;
    string *song;
public:
    Playlist(int size)
    {
        this->size = size;
        song = new string[size];
    }
    void setsong(int idx,string str)
    {
        if(idx<size)
        {
            song[idx] = str;
        }
        else
        {
            cout<<"idex out of bound!"<<endl;
        }
    }

    void display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<song[i]<<" ";
        }
        cout<<"\n";
    }
    Playlist(const Playlist &p)
    {
        size = p.size;
        song = new string[size];
        for(int i=0;i<size;i++)
        {
            song[i] = p.song[i];
        }
    }
    Playlist& operator=(const Playlist& p)
    {
        size = p.size;
        song = new string[size];
        for(int i=0;i<size;i++)
        {
            song[i] = p.song[i];
        }
    }
    ~Playlist()
    {
        delete[] song;
    }


};
int main()
{
    Playlist p(5);
    p.setsong(0,"song1");
    p.setsong(1,"song2");
    p.setsong(2,"song3");
    p.display();    
    Playlist p2 = p;
    p2.display();   
    p2.setsong(0,"newsong");
    p.display();    
    p2.display();   


    return 0;
}