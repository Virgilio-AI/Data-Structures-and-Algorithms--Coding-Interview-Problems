#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 10-07-20 14:53 --
using namespace std;			//{{ title }}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
int fastExpo(int a,long long n,int MOD);
//=====================		MAIN 	===================================
int main(){
cout<<fastExpo(5,13,1000000007);
return 0;
}
//======== FUNCIONES ========
int fastExpo(int a,long long n,int MOD){
	if(n==0){
		return 1;
	}
	if(n%2==0){
		return fastExpo((1ll*a*a)%MOD,n/2,MOD);
	}
	return (1ll*a*fastExpo(a,n-1,MOD))%MOD;
}
