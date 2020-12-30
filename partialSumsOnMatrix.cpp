#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 16-07-20 12:42 --
using namespace std;			//{{ title }}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
const int Nmax=1007;
int arr[Nmax][Nmax],n,m;
long sums[Nmax][Nmax];
int SumQuery(int l1,int l2,int c1,int c2){
	return (sums[l2][c2]-sums[l1-1][c2]-sums[l2][c1-1]+sums[l1-1][c1-1]);	
}
int ps(int n,int m){
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){			sum+=arr[i][j]; }
	}
	return sum;
}
void createPartialSumsArr(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sums[i][j]=ps(i,j);
		}
	}
}
void createPartialSumsArrFast(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sums[i][j]=sums[i][j-1]+sums[i-1][j]+arr[i][j]-sums[i-1][j-1];		
		}
	}
}
//=====================		MAIN 	===================================
int main(){
cin>>n;
cin>>m;
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		cin>>arr[i][j];
	}
}
createPartialSumsArrFast();
while(m--){
	int l1,l2,c1,c2;
	cin>>l1>>c1>>l2>>c2;
	cout<<SumQuery(l1,l2,c1,c2)<<"\n";
}
return 0;
}