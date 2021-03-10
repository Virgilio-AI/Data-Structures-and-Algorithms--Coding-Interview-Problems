#include<bits/stdc++.h>
using namespace std;
const int N = 100;
void fact(int k)
{
	map<int,int> mp;
	for(int i=2;i<=sqrt(k);i++)
	{
		int expo = 0;
		while(k%i==0)
		{
			expo++;
			k/= i;
		}
		if(expo!=0)
		{
			mp[i] = expo;
		}
	}
	if(k>1)
	{
		mp[k] = 1;
	}
	for(auto a:mp)
	{
		cout<<"("<<a.first<<"^"<<a.second<<")";
	}
	cout<<endl;
}


int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int k;
		cin>>k;
		fact(k);
	}
	return 0;
}

