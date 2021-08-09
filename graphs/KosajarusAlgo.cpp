#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,x2,x3,y,y2,y3;
const int N = 200;
int graph[N][N];
stack<int> st;
unordered_map<int,bool> visited;
int main()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			graph[i][j] = 0;
		}
	}
	graph[0][1] = 1;
	graph[1][2] = 1;
	graph[2][0] = 1;

	graph[1][3] = 1;

	graph[3][4] = 1;
	graph[5][3] = 1;
	graph[4][5] = 1;

	graph[6][5] = 1;

	graph[6][7] = 1;
	graph[7][8] = 1;
	graph[8][9] = 1;
	graph[9][7] = 1;

	graph[9][10] = 1;
	if(visited[0]) cout<<"visitado error"<<endl;
	visited[0] = 1;
	if(visited[0]) cout<<"visitado bien"<<endl;
	return 0;
}

