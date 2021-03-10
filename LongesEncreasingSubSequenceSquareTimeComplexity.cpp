//longgest encreasing subsequence in n^2 time complexity and n memory complexity
#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int dp[N];
int Arr[N];
int origin[N];
void printSubSequence(int n)
{
	if(origin[n] == -1)
	{
		cout<<Arr[n];
		return;
	}
	printSubSequence(origin[n]);
	cout<<" "<<Arr[n];
}

void solve(int n)
{
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(Arr[j] < Arr[i])
			{
				if(dp[j]+1 > dp[i])
				{
					dp[i] = dp[j]+1;
					origin[i] = j;
				}
			}

		}
	}
	cout<<"max size is:"<<dp[n-1]<<endl;
	cout<<"the sub sequence is:"<<endl;
	printSubSequence(n-1);
	cout<<endl;
}


int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>Arr[i];
	for(int i=0;i<n;i++) dp[i] = 1;
	for(int i=0;i<n;i++) origin[i] =-1;
	solve(n);
	return 0;
}


