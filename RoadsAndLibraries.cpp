#include<bits/stdc++.h>
using namespace std;
void initialize(bool visited[],int n)
{
	for(int i=0;i<=n;i++)
	{
		visited[i]=false;
	}
}
void dfs(int i,bool visited[],vector<int> adj[])
{
	visited[i]=true;
	for(int j=0;j<(int)adj[i].size();j++)
	{
		if(!visited[adj[i][j]] )
		{
			dfs(adj[i][j],visited,adj);
		}
	}
}
int main()
{
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int n,m;
		long long CL,CR;
		cin>>n>>m>>CL>>CR;
		vector<int> adj[n+1];
		bool visited[n+1];
		long connectedComponents=0;
		for(int j=0;j<n;j++)
		{
			int c1,c2;
			cin>>c1>>c2;
			adj[c1].push_back(c1);
			adj[c2].push_back(c2);
		}
		if(CL<=CR)
		{
			cout<<CL*CR<<endl;			
		}
		else
		{
			initialize(visited,n);
			for(int j=1;j<=n;j++)
			{
				if(visited[j]==false)
				{
					dfs(j,visited,adj);
					connectedComponents++;
				}
			}
			cout<<(connectedComponents*CL + (n-connectedComponents)*CR)<<endl;
		}
	}

	return 0;
}
