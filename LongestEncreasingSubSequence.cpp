#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int n,origin[N],dp[N],Arr[N];
int dpCont = 0;
int BinarySearchIndex(int i)
{
	int l = 0,r=dpCont;
	int ans;
	int mid;
	while(l<=r)
	{
		mid = (l+r)/2;
		if(Arr[dp[mid]] > Arr[i])
		{
			ans = mid;
			r = mid-1;
		}
		else
		{
			l = mid+1;
		}
	}
	return ans;
}
void printSubSequence()
{
	for(int i=0;i<=dpCont;i++) cout<<Arr[dp[i]]<<" ";
	cout<<endl;
}


			

void MaxIncreasingSubSequence()
{
	for(int i=1;i<n;i++)
	{
		if(Arr[dp[dpCont]] < Arr[i])
		{
			origin[i] = dp[dpCont];
			dpCont++;
			dp[dpCont] =i;
		}
		else
		{
			int indexToChange = BinarySearchIndex(i);
			dp[indexToChange] = i;
			if(indexToChange != 0 ) 
			{
				origin[i] = dp[indexToChange-1];
			}			
		}
	}
	cout<<"longest Incresing Subsequence size is:"<<endl;
	cout<<dpCont+1<<endl;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++) 
	{
		cin>>Arr[i];
		origin[i]=-1;
		dp[i] =0;
	}
	MaxIncreasingSubSequence();
	cout<<"Longest Incresing Subsequence is:"<<endl;
	printSubSequence();
	cout<<"arreglo de dp:"<<endl;
	for(int i=0;i<=dpCont;i++) cout<<dp[i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++) cout<<i<<" ";
	cout<<endl;
	for(int i=0;i<n;i++) cout<<origin[i]<<" ";
	cout<<endl;
	return 0;
}
