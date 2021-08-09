#include<bits/stdc++.h>
using namespace std;
const int N=100;
int y,y2,x,x2,sum,rows,columns,matrix[N][N];
int partialSumSubMatrix[N][N],bMatrix[N][N];
void partialSums()
{
	bMatrix[x][y]+=sum;
	bMatrix[x][y2+1]-=sum;
	bMatrix[x2+1][y]-=sum;
	bMatrix[x2+1][y2+1]+=sum;
}
void CreateFinalArray()
{
	for(int i=1;i<=rows;i++)
	{
		for(int j=1;j<=columns;j++)
		{
			partialSumSubMatrix[i][j] = partialSumSubMatrix[i][j-1] + partialSumSubMatrix[i-1][j] + bMatrix[i][j] - partialSumSubMatrix[i-1][j-1];
		}
	}
}
void updateMatrix()
{
	for(int i=1;i<=rows;i++)
	{
		for(int j=1;j<=columns;j++)
		{
			matrix[i][j]+=partialSumSubMatrix[i][j];
		}
	}	
}
int main()
{
	cin>>rows>>columns;
	for(int i=1;i<=rows;i++)
	{
		for(int j=1;j<=columns;j++)
		{
			cin>>matrix[i][j];
		}
	}
	int queries;
	cin>>queries;
	while(queries--)
	{
		cin>>x>>x2>>y>>y2>>sum;
		partialSums();
	}
	CreateFinalArray();
	updateMatrix();
	for(int i=1;i<=rows;i++)
	{
		for(int j=1;j<=columns;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}