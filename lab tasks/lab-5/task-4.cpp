#include <iostream>
#include<vector>
using namespace std;

bool isSafe(vector<int>& board,int rows,int col)
{
    for(int i=0;i<rows;i++)
    {
        if(board[i] == col || abs(board[i] - col) == abs(i - rows))
        {
            return false;
        }
    }

    return true;
}

void Nqueens(vector<int>& board,int n,int rows,vector<vector<int>>& sol)
{
    if(rows == n)
    {
        sol.push_back(board);
        return;
    }

    for(int col = 0;col<n;col++)
    {
        if(isSafe(board,rows,col))
        {
            board[rows] = col;

            Nqueens(board,n,rows+1,sol);

            board[rows] = -1;

        }
    }


}

int main() 
{
    int n;
    cout<<"Enter the size of the board: ";
    cin>>n;  
    vector<int>board(n,-1);

    vector<vector<int>> solutions;
    Nqueens(board, n, 0, solutions);

    cout << "Total solutions = " << solutions.size() << "\n";
    for (vector<int> sol : solutions) {
        for (int col : sol) {
            cout << col << " ";
        }
        cout << "\n";
    }

    return 0;
}