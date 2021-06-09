//Fri May 21 06:33:18 PM CDT 2021
//created by: rockhight
#include<bits/stdc++.h>    
using namespace std;
//general functions I/O input c style array, input c style array randomly, output array 
void cinArr(int n,int arr[]){for(int i=1;i<=n;i++){cin>>arr[i];}}
void cinrArr(int n,int k,int arr[]){for(int i=1;i<=n;i++){arr[i] = rand()%k;}}
void coutArr(int n,int arr[]){for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}}
int n,m,z,x,x2,x3,y,y2,y3;
const int N = 100;
//=====================		MAIN 	===================================
int arr[N];
//int mat[N][N];
void solve()
{
	//inserting
	for(int i=2;i<=n;i++)
	{
		int h = i;
		while(h>1 && arr[h] > arr[h/2])
		{
			swap(arr[h],arr[h/2]);
			h = h/2;
		}
	}
	//popping out
	for(int i=n;i>1;i--)
	{
		int p = 1;
		swap(arr[p],arr[i]);
		while(p*2 < i && arr[p*2] > arr[p] || p*2 + 1 < i && arr[p*2+1] > arr[p])
		{
			if(p*2 + 1 >= i || arr[p*2+1] < arr[p*2] ) 
			{
				swap(arr[p*2],arr[p]);
				p = p*2;
			}
			else
			{
				swap(arr[p*2+1],arr[p]);
				p = p*2+1;
			}
		}
	}
}
					
int main()
{
	srand(time(NULL));
	n = 10;
	cinrArr(n,10,arr);
	coutArr(n,arr);cout<<endl;
	solve();
	coutArr(n,arr);
	return 0;
}
