#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int a[N],n;
int solve()
{
	int sum=0,ans=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		ans=max(sum,ans);
		sum = (sum<0) ? 0:sum;
	}
	return ans;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<solve();
	return 0;
}