#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,cur_rem,fr[N]={0};

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cur_rem = (cur_rem*10 +1)%n;
		if(cur_rem == 0)
		{
			for(int j=0;j<i;j++)
			{
				cout<<1;
			}
			return 0;
		}
			if(fr[cur_rem] != 0 )
			{
				for(int j=0;j<i-fr[cur_rem];j++) cout<<1;
				for(int j=0;j<fr[cur_rem];j++) cout<<0;
				return 0;
			}
			fr[cur_rem]=i;
	}	
	return 0;
}


