#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> Points;
void BinarySearchAnswer();
bool IsValidDistance(int m);

int main()
{
    //input of all points
    cin>>n;
    while(n--)
    {
        int x,y;
        cin>>x>>y;        
        Points.emplace_back(x,y);
    }     
    BinarySearchAnswer();
}

void BinarySearchAnswer()
{
    //we sort the points in ascending form
    //the we execute a binary search with help 
    //of the function IsValidDistance    
    int Left=0,Right=1'000'000,answer;
    sort(Points.begin(),Points.end());
    while(Left<=Right)
    {
        int Distance=(Left+Right)/2;
        if(IsValidDistance(Distance))
        {
            Left = Distance+1;
            answer=Distance;
        }
        else
        {
            Right = Distance-1;            
        }
    }    
    cout<<"answer:"<<answer<<endl;    
}
//tells us if the currend Distance is valid
//that is if there is any pair of points such that 
//Distance <= min(abs(xi-xj),abs(yi-yj))
bool IsValidDistance(int Distance)
{
    int NumberOfPoints = Points.size();
    //initialize the biggest minimum and the smallest maximum
    int LeftPointer=-1,MinimumY=1'000'000,MaximumY=-1'000'000;
    for(int i=0;i<NumberOfPoints;i++)
    {
        //set a range from LeftPointer + 1 to i and 
        //so that abs(xi-xj) >= Distance and
        //checks if there is some abs(yi-yj)
        while(LeftPointer + 1 < i && Points[i].first - Points[LeftPointer+1].first >=Distance)
        {
            LeftPointer++;
            MinimumY = min(MinimumY,Points[LeftPointer].second);
            MaximumY = max(MaximumY,Points[LeftPointer].second);
        }
        if(LeftPointer != -1 && abs(MinimumY - Points[i].second) >= Distance) return true;
        if(LeftPointer != -1 && abs(MaximumY - Points[i].second) >= Distance) return true; 
    }    
    return false;
}
