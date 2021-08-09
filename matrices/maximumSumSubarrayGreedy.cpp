#include<bits/stdc++.h>
using namespace std;
/*
problem statement:
create a program that given an array of integers you can 
find the maximum sum sub array in the the current array,
example:
in:
6
-20 5 3 10 -13 12
out:
18
*/

int n;
int MaximumSumSubArray(int arr[])
{
	int ans=arr[0],sum=0;
	//you iterate over all the elements in the list 
	//and you acumulate a sum variable
	//if the sum variable is less than cero you will 
	//reset the value of sum to 0
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		if(sum<0) sum=0;
		ans = max(ans,sum);
	}
	return ans;
}

int main()
{
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	cout<<MaximumSumSubArray(arr)<<endl;
	return 0;
}

