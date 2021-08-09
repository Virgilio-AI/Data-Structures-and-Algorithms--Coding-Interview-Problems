#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long MOD = 100000007;
long long FastExpo(long long m,long long k, long long MOD)
{
	if(k==0) return 1;
	if(k%2==0)
	{
		return FastExpo(m*m,k/2,MOD);
	}
		return m*FastExpo(m,k-1,MOD);
}

int main()
{
	cin>>n;
	while(n--)
	{
		cin>>m>>k;
		cout<<FastExpo(m,k,MOD);
	}
	return 0;
}


