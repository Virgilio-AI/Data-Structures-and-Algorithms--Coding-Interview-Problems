#include<bits/stdc++.h>
using namespace std;
unsigned short Rows,Columns;
const unsigned short N = 100;
char Matrix[N][N];
bool Visited[N][N]={false};
const short XDirections[4] = {0,1,0,-1};
const short YDirections[4] = {1,0,-1,0};
void FillAlgorithm(int Column,int Row,unsigned int &Counter)
{    
    Visited[Column][Row]=true;    
    for(int i=0;i<3;i++)
    {
        int XPosition=Column+XDirections[i];
        int YPosition=Column+YDirections[i];
        if(XPosition>-1 && YPosition>-1 && XPosition < Rows && YPosition<Columns && !Visited[XPosition][YPosition] && Matrix[XPosition][YPosition] == '.')
        {            
            Counter++;
            FillAlgorithm(Column,Row,Counter);
        }
    }
}
void FinIslands()
{
    cout<<"hola1"<<endl;
    unsigned int NumberOfIslands=0,MaxIsland=0;
    for(int i=0;i<Rows;i++)
    {
        for(int j=0;j<Columns;j++)
        {
            if(Matrix[i][j]=='.' && Visited[i][j]==false)
            {
                NumberOfIslands++;                
                unsigned int Counter=1;
                FillAlgorithm(i,j,Counter);
                
                MaxIsland = max(MaxIsland,Counter);                
                cout<<NumberOfIslands<<" "<<MaxIsland<<endl;
            }
        }
    }
    cout<<NumberOfIslands<<" "<<MaxIsland<<endl;
    cout<<"hola"<<endl;
}
int main()
{
    cout<<"hola tghrfdhgern etnrthnhertnrt nrtnrht nrthnrht nfghnfgnnfhnfgnhgfjhjfghjfgjhfg jfgjfgh fgh jfghjhfgfgj"<<endl;
    // cin>>Rows>>Columns;
    // cout<<Rows<<Columns;
    // for(int i=0;i<Rows;i++)
    // {
    //     for(int j=0;j<Columns;j++)
    //     {
    //         cin>>Matrix[i][j];
    //     }
    // }
    // FinIslands();
    return 0;
}
/*
sample input:
5 5
. # . # #
# . . # .
# . # . .
# . . # #
. . # . .
*/