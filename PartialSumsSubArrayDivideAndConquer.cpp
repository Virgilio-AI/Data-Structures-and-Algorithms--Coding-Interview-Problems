#include<bits/stdc++.h>
using namespace std;

int maxLeftSum(vector<int> vec,int left,int mid)
{
	int sum=0,maxS=vec[mid];
	for(int i=mid;i>=left;i--)
	{
		sum+=vec[i];
		maxS=max(maxS,sum);
	}
	return maxS;
}

int maxRightSum(vector<int> vec,int midPlusOne,int right)
{
	int sum=0,maxS=vec[midPlusOne];
	for(int i=midPlusOne;i<=right;i++)
	{
		sum+=vec[i];
		maxS=max(maxS,sum);
	}
	return maxS;
}
int solve(vector<int> a,int left,int right)
{
	if(left==right)
	{
		return a[right];
	}
	int mid=(left+right)/2;
	int ans=max(solve(a,left,mid),solve(a,mid+1,right));
	return max(ans,maxRightSum(a,mid+1,right)+maxLeftSum(a,left,mid));
}
int main()
{
	int n;
	vector<int> vec;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		vec.push_back(temp);
	}
	cout<<solve(vec,0,n-1);
	return 0;
}


