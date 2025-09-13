#include<iostream>
using namespace std;

class vector2D
{
private:
    int **arr;
    int rows;
    int col;
public:
    vector2D(int r,int c,int val)
    {
        arr = new int*[r];
        for(int i=0;i<r;i++)
        {
            arr[i] = new int[c];
        }
        rows =r;
        col = c;

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                arr[i][j] = val;
            }
        }
    }

    void print()
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    } 

    void resize(int newRows, int newCols, int fill = 0) {
        int** newData = new int*[newRows];
        for (int i = 0; i < newRows; ++i)
        {
            newData[i] = new int[newCols];
            for (int j = 0; j < newCols; ++j) 
            {
                if (i < rows && j < col) 
                {
                    newData[i][j] = arr[i][j];
                } else 
                {
                    newData[i][j] = fill;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;
        
        rows = newRows;
        col = newCols;
        arr = newData;
    }


    void transpose() {
        int** newData = new int*[col];
        for (int i = 0; i < col; i++) 
        {
            newData[i] = new int[rows];
            for (int j = 0; j < rows; j++)
            {
                newData[i][j] = arr[j][i];
            }
        }

        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;
        swap(rows, col);
        arr = newData;
    }

    void printWithOffsetForOddIndices()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int value = arr[i][j];
                if ((i * col + j) % 2 != 0) {
                    value += 2;
                }
                cout<<value<<" ";
            }
            cout << '\n';
        }
    }

    ~vector2D()
    {
        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }





};


int main()
{
    vector2D v2(3,3,2);
    v2.print();
    v2.resize(4,4,6);
    v2.print();

    v2.printWithOffsetForOddIndices();

    v2.transpose();

    v2.print();
    return 0;
}