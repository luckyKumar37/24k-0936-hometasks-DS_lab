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

bool iceCreamShop(vector<vector<int>>& sol,int x,int y,vector<vector<int>>& grid)
{
    if((x >= 0 && x == grid[0].size() - 1) && (y >= 0 && y == grid[0].size() - 1))
    {
        sol[x][y] = 1;
        return true;
    }

    if(isSafe(x,y,grid))
    {
        sol[x][y] = 1;

        // down
        if(iceCreamShop(sol,x+1,y,grid))
        {
            return true;
        }

        // right
        if(iceCreamShop(sol,x,y+1,grid))
        {
            return true;
        }

        // up
        if(iceCreamShop(sol,x-1,y,grid))
        {
            return true;
        }

        // left
        if(iceCreamShop(sol,x,y-1,grid))
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
        {1, 0, 1, 1, 1, 0, 1},
        {1, 1, 1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 0, 1},
        {0, 0, 1, 1, 1, 1, 1}
    };

    vector<vector<int>> sol(7,vector<int>(7,0));

    if(iceCreamShop(sol,0,0,grid))
    {
        for(int i=0;i<7;i++)
        {
            for(int j=0;j<7;j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;    
            
        }
    }
    else
    {
        cout<<"child can't reach the ice crea shop\n";
    }

    return 0;
}