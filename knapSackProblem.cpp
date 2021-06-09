#include<bits/stdc++.h>
using namespace std;
//knap sack problem using a matrix of dp
const int N = 100;
int dp[N][N];
int weight[N];
int valor[N];
int n,k;
int solve()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			int preValid = j - weight[i];
			if(preValid<0)
			{
				dp[i][j] = dp[i-1][j];
				continue;
			}
			dp[i][j] = max(dp[i-1][preValid] + valor[i], dp[i-1][j]);
		}
	}
	return dp[n][k];
}
void reconstruir(int i,int j)
{
	if(i==0 || j==0) return;
	if(dp[i-1][j] == dp[i][j] ) 
	{		
		reconstruir(i-1,j);		
		cout<<0<<" ";
	}
	else
	{
		reconstruir(i-1,j-weight[i]);
		if(j-weight[i]<=0) cout<<0<<" ";
		cout<<1<<" ";
	}
}
int main()
{
	cin>>n>>k;
	weight[0] = valor[0] = 0;
	for(int i=1;i<=n;i++) cin>>valor[i];
	for(int i=1;i<=n;i++) cin>>weight[i];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++) dp[i][j] = 0;
	}
	cout<<solve()<<endl;
	cout<<"matriz de dp"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"recontruccion del algoritmo"<<endl;
	reconstruir(n,k);
	return 0;
}		       
