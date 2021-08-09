#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 300;
int arr[N];
mt19937 generator (time(NULL));
uniform_real_distribution<double> dis(0.0, 1.0);

void InsertionSort()
{
	for(int i=1;i<n;i++)
	{
		int index = i;
		while(index>0 && arr[index] < arr[index-1])
		{
			swap(arr[index],arr[index-1]);
			index--;
		}
	}
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		arr[i] = dis(generator)*10;
	}
	cout<<"antes de la insercion"<<endl;
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<endl;
	InsertionSort();
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	return 0;
}

	
