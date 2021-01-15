/*
Problem statement:
You are given a 2d grid map of '.'s(land) and '#'(water). AN island island is formed
by connecting adjacent land cells horizontally or vertivally and is surrounded by water.
Find the numbers of islands and the max.numbers of cells of one island

sample input:
5 6
. # . # # .
# . . # . .
# . # . . #
# . . # # .
. . # . . .

output:
8
4
*/
#include<bits/stdc++.h>
using namespace std;
const int N =100;
//visited positions
char Map[N][N];
bool bMap[N][N];
int Columns,Rows;
int MaxSizeIsland,NumberOfIslands=0;
//the directions up,right,down,left respectively
int DirX[4] = {0,1,0,-1},DirY[4] = {1,0,-1,0};
bool Valid(int Row,int Column)
{
    return (Row > 0 && Row <= Rows && Column > 0 && Column <=Columns && !bMap[Row][Column] && Map[Row][Column] == '.');
}
void FillAlgorithm(int Row,int Column,int &SizeOfIsland)
{
    SizeOfIsland++;
    bMap[Row][Column] = true;
    for(int i =0;i<4;i++)
    {
        if(Valid(Row+DirY[i],Column+DirX[i]))
        {
            FillAlgorithm(Row+DirY[i],Column+DirX[i],SizeOfIsland);
        }
    }
}
// a simple iteration over the Matrix of characters Map
// where if not visited and if you are in land, you enter the 
// function FillAlgorithm that visites al continuous lands(points '.')

void MapIteration()
{
    for(int i=1;i<=Rows;i++)
    {
        for(int j=1;j<=Columns;j++)
        {
            if(!bMap[i][j] && Map[i][j] == '.')
            {
                int SizeOfIsland=0;
                FillAlgorithm(i,j,SizeOfIsland);
                NumberOfIslands++;
                MaxSizeIsland = max(MaxSizeIsland,SizeOfIsland);
            }
        }
    }
}
int main()
{
    cin>>Rows>>Columns;
    for(int i=1;i<=Rows;i++)
    {
        for(int j=1;j<=Columns;j++)
        {
            cin>>Map[i][j];
        }
    }
    cout<<endl;
    MapIteration();
    cout<<NumberOfIslands<<" "<<MaxSizeIsland<<endl;
    return 0;
}
