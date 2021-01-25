#include<bits/stdc++.h>
using namespace std;
const int N = 100;
bool fr[N]={0};
/*
 * given an array of n integers find the longest consecutive number subarray,
 * so a consecutive number subarray is a subarray that if we sort the numbers the given subarray is going to be consecutive
 * for example 1 4 3 2 is a consecutive subarray and 1 4 2 is not because is missing the 3 to be consecutive
 * examples:
 * in:
 * 5
 * 1 4 3 2 25
 * out: 4
 *
 * in:
 * 4
 * 1 3 2 5
 * out:
 * 3
 */

int LongestConsecutiveNumsSubArray(int n,int arr[N])
{
	// we will use the sliding window tecnique so we can solve the problem in n^2
	// given the observation that 1 condition has to be acomplished to have a consecutive 
	// sub array,the biggest element minus the smaller has to be equal to the difference between the right position
	//and the left position(the length) of the sub array
	// and other condition has to be that there is no element repeated in the sub array, thus we will have an array of frequences
	int ans=0;
	for(int left = 0;left<n;left++)
	{
		for(int i=0;i<n;i++)
		{
			fr[arr[i]]=false;
		}
		int Min = arr[left],Max=arr[left];
		for(int right = left;right<n;right++)
		{
			if(fr[arr[right] ] == true)
			{
				break;
			}
			fr[arr[right]]=true;
			Min = min(Min,arr[right]);
			Max = max(Max,arr[right]);
			if(right-left == Max-Min)
			{
				ans = max(ans,right-left+1);
			}
		}
	}
	return ans;
}
int main()
{
	int arr[N],n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<LongestConsecutiveNumsSubArray(n,arr)<<endl;
	return 0;
}

