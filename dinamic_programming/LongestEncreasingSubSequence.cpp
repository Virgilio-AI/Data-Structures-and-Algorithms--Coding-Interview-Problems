#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int dp[N],R[N],arr[N],dpCont=-1,n;
int BinarySearchIndex(int i )
{
	int l = 0,r=dpCont;
	int ans;
	while(l<=r)
	{
		int m = (l+r)/2;
		if(arr[i] > arr[dp[m]])
		{
			ans = m;
			r = m-1;
		}
		else
		{
			l = m+1;
		}
	}
	return ans;
}


void LongestDecreasingSubSequence()
{
	for(int i=0;i<n;i++)
	{
		if(dpCont == -1 || dpCont != -1 && arr[i] < arr[dp[dpCont]])
		{
			dpCont++;
			dp[dpCont] = i;
			R[i] = (dpCont == -1) ? -1 : dp[dpCont-1];
		}
		else
		{
			int index = BinarySearchIndex(i);
			dp[index] = i;
			R[i] = (index == 0 ) ? -1 : dp[index-1];
		}
	}
}
void printSubSequence(int index)
{
	if(index == -1) return;
	printSubSequence(R[index]);
	cout<<arr[index]<<" ";
}

int main()
{
	cin>>n;
	for(int i =0;i<n;i++)cin>>arr[i];
	for(int i =0;i<n;i++)
	{
		R[i] = -1;
		dp[i] = 0;
	}


	LongestDecreasingSubSequence();
	cout<<dpCont+1<<endl;
	printSubSequence(dp[dpCont]);
	return 0;
}

