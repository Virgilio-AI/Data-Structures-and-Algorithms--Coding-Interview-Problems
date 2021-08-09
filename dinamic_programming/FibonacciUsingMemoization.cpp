#include<bits/stdc++.h>
using namespace std;
const int N = 500;
unsigned long long memo[N]={0};
unsigned long long Fibonnacci(int k)
{
	if(k==1 || k== 2) return 1;
	unsigned long long minusOne = (memo[k-1]!=0) ? memo[k-1] : Fibonnacci(k-1);
	unsigned long long minusTwo = (memo[k-2]!=0) ? memo[k-2] : Fibonnacci(k-2);
	memo[k] = minusOne + minusTwo;
	return minusOne + minusTwo;
}
int main()
{
	int n;
	memo[1] = 1;
	memo[2]=1;
	cout<<"input a number n to calculate Fibonacci(n)"<<endl;
	cin>>n;
	Fibonnacci(n);
	for(int i=1;i<=n;i++)
	{
		cout<<memo[i]<<" ";
	}

}
