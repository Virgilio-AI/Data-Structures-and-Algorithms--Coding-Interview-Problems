/*
problem statement:
given a matrix of n rows and m columns, answer for each k query.
find the sum of all the elements inside the square given the coordinates of the upper left corner (l1,c1)
and the coordinates of the lower right coordinate(l2,c2)
input example:
3 3//the number of rows and columns
1 2 3 //the input matrix
4 5 6//the input matrix
7 8 9//the input matri
3//the number of queries
1 1 2 2 //the queries
2 2 3 3//the queries
3 3 3 3 //the queries
*/

#include<bits/stdc++.h>
using namespace std;
const int N=100;
int Rows,Columns;
int Queries,Matrix[N][N],PartialSumsSubMatrix[N][N];
int x,x2,y,y2;
//the creation of the partial sum submatrix, the partial sum sub matrix is basicly defined as 
//PartialSumsSubMatrix[i][j] = the sum of all the elements in the matrix from Row=1 and Column=1 
//to Row = i and Column + j
// so for example the ,matrix
//1 2 
//3 4 
//has a partial sum submatrix of 
//1 3
//4 10
void CreatePartialSumSubMatrix()
{
	for(int i=1;i<=Rows;i++)
	{
		for(int j=1;j<=Columns;j++)
		{
			PartialSumsSubMatrix[i][j] = Matrix[i][j] + PartialSumsSubMatrix[i-1][j] + PartialSumsSubMatrix[i][j-1] - PartialSumsSubMatrix[i-1][j-1];
		}
	}
}
//just a very intuitive propertie of the partial sum submatrix lets us know that the sum
//of all the elements in the  sub matrix x y, x2 y2 is this result
int PartialSumSubMatrixQuerie()
{
	return PartialSumsSubMatrix[x2][y2] + PartialSumsSubMatrix[x-1][y-1] - PartialSumsSubMatrix[x-1][y2] - PartialSumsSubMatrix[x2][y-1];
}
int main()
{
	cin>>Rows>>Columns;
	for(int i=1;i<=Rows;i++)
	{
		for(int j=1;j<=Columns;j++)
		{
			cin>>Matrix[i][j];
		}
	}
	CreatePartialSumSubMatrix();
	cin>>Queries;
	while(Queries--)
	{
		cin>>x>>y>>x2>>y2;
		cout<<PartialSumSubMatrixQuerie()<<endl;		
	}	

	return 0;
}
