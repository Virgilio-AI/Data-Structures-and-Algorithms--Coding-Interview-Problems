#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 27-07-20 12:42 --
using namespace std;			//{{ title }}
void cinArr(int n,int arr[]){for(int i=1;i<=n;i++){cin>>arr[i];}}
void coutArr(int n,int arr[]){for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
const int Nmax=100000007;const double pi = 2*acos(0.0);
int n,m,x,y,z,w,arr[Nmax];

void seleccion(){
	for(int i=1;i<=n;i++){
		int pos=i;
		for(int j=i+1;j<=n;j++){
			if(arr[j]<arr[pos])
				pos=j;
		}
		swap(arr[i],arr[pos]);
	}
}
//=====================		MAIN 	===================================
int main(){
ios::sync_with_stdio(0);
cin>>n;
cinArr(n,arr);
seleccion();
coutArr(n,arr);
return 0;
}

