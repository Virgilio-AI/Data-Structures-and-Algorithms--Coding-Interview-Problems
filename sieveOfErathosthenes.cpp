#include<bits/stdc++.h>
using namespace std;
int n,k;
const int MaxNum = 1000000;
bool sieve[MaxNum];
void MakeSieve()
{
	for(int i=2;i<sqrt(MaxNum);i++)
	{
		if(sieve[i])
		{
			int element = i;
			for(int j=element*2;j<=MaxNum;j+=element) sieve[j] = false;
		}
	}
}

void SieveQuery(int k)
{
	for(int i=1;i<=k;i++)
	{
		if(sieve[i])
		{
			cout<<i<<" ";
		}
	}
	cout<<endl;
}

int main()
{
	for(int i=0;i<MaxNum;i++) sieve[i] = true;
	cin>>n;
	MakeSieve();
	while(n--)
	{
		cin>>k;
		SieveQuery(k);
	}

	return 0;
}

