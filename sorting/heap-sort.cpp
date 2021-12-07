// Fecha: 12/December/2021 - Sunday
// Autor: Virgilio Murillo Ochoa
// personal github: Virgilio-AI
// linkedin: https://www.linkedin.com/in/virgilio-murillo-ochoa-b29b59203
// contact: virgiliomurilloochoa1@gmail.com
#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int n,m,k,x,x2,x3,y,y2,y3,z,z2,z3,t1,t2,t3,ans;
void imat(int mat[N][N]);
void iar(int ar[N]);
void par(int ar[N],int m);
void pmat(int mat[N][N],int n,int m);
int arr[N] = {0};

void heap()
{
	// heap insertion
	for(int i=1;i<n;i++)
	{
		int h = i;
		while(h >=1 && arr[h] > arr[h/2])
		{
			swap(arr[h],arr[h/2]);
			h = h/2;
		}
	}


	// heap deletion
	for(int i=n-1;i>0;i--)
	{
		int p = 0;
		swap(arr[p],arr[i]);
		while( p*2 < i && arr[p*2] > arr[p] || p*2 + 1 < i && arr[p*2+1] > arr[p] )
		{
			if(p*2+1 > i || arr[p*2+1] < arr[p*2])
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
	// float num = rand()%maxNUm;
	srand(time(NULL));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		arr[i] = rand()%10;
	}
	par(arr,n);
	heap();
	par(arr,n);
	return 0;
}



void par(int ar[N],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
	cout<<endl;
}

void pmat(int mat[N][N],int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void imat(int mat[N][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			mat[i][j] = 0;
		}
	}
}

void iar(int ar[N])
{
	for(int i=0;i<N;i++)
	{
		ar[i] = 0;
	}
}

