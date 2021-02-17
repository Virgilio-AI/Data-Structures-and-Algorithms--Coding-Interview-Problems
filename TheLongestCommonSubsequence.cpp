#include<bits/stdc++.h>
using namespace std;
const int N = 101;
int n,m,arr1[N],arr2[N],dp[N][N]={0};
void TheLongestCommonSubSequence()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(arr1[i] == arr2[j])
			{
				dp[i][j] = dp[i-1][j-1] + 1;	
			}
			else
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
}
void RebuildArray(int i,int j)
{
	if(dp[i][j] == 0) return;
	if(arr1[i] == arr2[j])
	{
		RebuildArray(i-1,j-1);
		cout<<arr1[i]<<" ";
	}
	else
	{
		if(dp[i-1][j] >= dp[i][j-1])
		{
			RebuildArray(i-1,j);
		}
		else
		{
			RebuildArray(i,j-1);
		}		
	}
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>arr1[i];
	for(int j=1;j<=m;j++) cin>>arr2[j];
	TheLongestCommonSubSequence();
	RebuildArray(n,m);
	return 0;
}
