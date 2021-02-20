#include<bits/stdc++.h>
using namespace std;
const int N = 101;
const int M = 10001;
int n,m;
long long dp[M]={-1};
long long monedas[N];
long long rec(int ele)
{
	if(ele==0) return 0;
	long long mini = m;
	for(int i=1;i<=n;i++)
	{
		int number = ele-monedas[i];
		if(number<0) continue;
		long long toCompare = (dp[number] != -1) ? dp[number]+1:rec(number)+1;
		mini = min(mini,toCompare);
	}
	dp[ele]=mini;
	return mini;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>monedas[i];
	}
	dp[0] =0;
	for(int j=1;j<=m;j++) dp[j] = -1;
	cout<<rec(m)<<endl;
	return 0;
}

