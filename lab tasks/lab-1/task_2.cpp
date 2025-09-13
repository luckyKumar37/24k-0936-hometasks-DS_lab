#include<iostream>
#include<string>
using namespace std;
class StudentRecord
{
private:
    int size;
    int *marks;
public:
    StudentRecord(int size)
    {
        this->size = size;
        marks = new int[size];
        for(int i=0;i<size;i++)
        {
            marks[i] = 0;
        }
    }
    void setMarks(int idx,int val)
    {
        if(idx<size)
        {
            marks[idx] = val;
        }
        else
        {
            cout<<"index out of bound"<<endl;
        }
    }
    void display()
    {
        for(int i=0;i<size;i++)
        {
        cout<<marks[i]<<" ";
        }
        cout<<endl;
    }
    ~StudentRecord()
    {
        delete[] marks;
    }

 
};
int main()
{
    StudentRecord st(5);
    st.setMarks(0,1);
    st.setMarks(1,2);
    st.setMarks(2,3);
    st.setMarks(3,4);
    st.setMarks(4,5);
    st.display();
    StudentRecord st2 = st;
    st2.display();
    st2.setMarks(0,5);
    st.display();
    st2.display();

    return 0;
}