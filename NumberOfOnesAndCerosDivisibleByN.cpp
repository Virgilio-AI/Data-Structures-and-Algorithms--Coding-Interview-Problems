#include<bits/stdc++.h>
using namespace std;
const int N = 100 ;
/*
 * problem statement:
 * given a number n, print a number k such that k%n=0 and k is composed of only ones and ceros
 */

int n,pos[N]={0};
int main()
{
	cin>>n;
	int cur_rem =0;
	//given that the pidgeonhole principle and that if two numbers are congruent to mod n
	//the difference of thouse two numbers is divisible by n
	//so by that principle we must find two numbers composed of ones and ceros that have the same reminder
	//when divided by n and then substrackt the bigger one from the smaller
	//the answer obviously is going to be a number only composed of ones and ceros
		
	for(int i=1;i<=n;i++)
	{
		cur_rem = (cur_rem*10 +1)%n;
		if(cur_rem == 0)
		{
			for(int j=1;j<=i;j++) cout<<1;
			return 0;
		}
		if(pos[cur_rem] !=0)
		{
			for(int j=1;j<=i-pos[cur_rem];j++) cout<<1;
			for(int j=1;j<=pos[cur_rem];j++) cout<<0;
			return 0;
		}
		pos[cur_rem]=i;
	}
	return 0;
}

