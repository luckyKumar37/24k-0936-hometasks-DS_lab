#include <iostream>
#include<vector>
using namespace std;

bool isSafe(int x,int y,vector<vector<int>>& grid)
{
    if((x < grid[0].size()) && (y < grid[0].size()) && (grid[x][y] == 1))
    {
        return true;
    }

    return false;
}

bool ratInAMaze(vector<vector<int>>& sol,int x,int y,vector<vector<int>>& grid)
{
    if((x == grid[0].size() - 1) && (y == grid[0].size() - 1))
    {
        sol[x][y] = 1;
        return true;
    }

    if(isSafe(x,y,grid))
    {
        sol[x][y] = 1;

        if(ratInAMaze(sol,x+1,y,grid))
        {
            return true;
        }

        if(ratInAMaze(sol,x,y+1,grid))
        {
            return true;
        }

        sol[x][y] = 0;
        return false;
    }

    return false;


}

int main() 
{
    vector<vector<int>> grid = {
        {1,0,1,0,1},
        {1,1,1,1,1},
        {0,1,0,1,1},
        {1,0,0,1,1},
        {1,1,1,0,1}
    };

    vector<vector<int>> sol(5,vector<int>(5,0));

    if(ratInAMaze(sol,0,0,grid))
    {
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;    
            
        }
    }
    else
    {
        cout<<"Lion can't reach the meat!"<<endl;
    }


    return 0;
}