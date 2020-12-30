#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 27-07-20 12:42 --
using namespace std;			//{{ title }}
void cinArr(int n,int arr[]){for(int i=1;i<=n;i++){cin>>arr[i];}}
void coutArr(int n,int arr[]){for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
const int Nmax=100000007;const double pi = 2*acos(0.0);
int n,m,x,y,z,w,arr[Nmax];

void insercion(){
	for(int i=2;i<=n;i++){
		int j=i;
		while(j>=2&&arr[j]<arr[j-1]){
			swap(arr[j],arr[j-1]);
			j=j-1;
		}
	}
}
//=====================		MAIN 	===================================
int main(){
ios::sync_with_stdio(0);
cin>>n;
cinArr(n,arr);
insercion();
coutArr(n,arr);
return 0;
}

