#include<bits/stdc++.h>
using namespace std;
const int N = 100;
//visited positions
bool Visited[N][N]={false};
char Map[N][N];
int Rows,Columns;
//the directions up,right,down,left respectively
int XDirections[4] = {0,1,0,-1};
int YDirections[4] = {-1,0,1,0};

void IterarteMap();
void FillAlgorithm(int Rows,int Columns,int &Counter);

int main()
{
    cin>>Rows>>Columns;
    for(int i=0;i<Rows;i++)
    {
        for(int j=0;j<Columns;j++)
        {
            cin>>Map[i][j];
        }
    }
    IterarteMap();    
    return 0;
}
// a simple iteration over the Matrix of characters Map
// where if not visited and if you are in land, you enter the 
// function FillAlgorithm that visites al continuous lands(points '.')
void IterarteMap()
{
    int MaxIsland=0,NumberOfIslands=0;
    for(int i=0;i<Rows;i++)
    {
        for(int j=0;j<Columns;j++)
        {            
            if(!Visited[i][j] && Map[i][j] == '.')
            {
                int Counter=0;
                NumberOfIslands++;                
                FillAlgorithm(i,j,Counter);
                MaxIsland = max(MaxIsland,Counter);
            }
        }
    }    
    cout<<"Maximum Island:"<<MaxIsland<<"\nNumber of Islands:"<<NumberOfIslands;
}

void FillAlgorithm(int Row,int Column,int &Counter)
{
    Visited[Row][Column]=true;
    Counter++;
    for(int i=0;i<4;i++)
    {
        int XDirection = Column + XDirections[i];
        int YDirection = Row + YDirections[i];        
        if(XDirection>=0 && YDirection >=0 && XDirection < Columns && YDirection < Rows && Map[YDirection][XDirection] == '.' && !Visited[YDirection][XDirection])
        {
            FillAlgorithm(YDirection,XDirection,Counter);
        }
    }
}
/*
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